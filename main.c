#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>
#include <errno.h>
#include "syscall_map.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        puts("No program specified!");
        return 1;
    }

    int newArgc = argc - 1;
    char** newArgv = malloc((newArgc + 1) * sizeof(char*));

    int status;
    long syscall_number;
    int in_syscall = 0;
    struct user_regs_struct regs;

    for (int i = 0; i < newArgc; i++) {
        newArgv[i] = strdup(argv[i+1]);
    }
    newArgv[newArgc] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        // child
        ptrace(PTRACE_TRACEME); // ask parent to be traced

        if (execvp(argv[1], newArgv) == -1) {
            printf("Error running execvp, errno: %d\n", errno);
            return 1;
        }
    }
    else {
        // parent
        ptrace(PTRACE_ATTACH, pid, 0, 0);
        waitpid(pid, NULL, 0);

        while (1) {
            // Wait for syscall
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            waitpid(pid, &status, 0);

            if (in_syscall) {
                in_syscall = 0;
            }
            else {
                in_syscall = 1;
                continue;
            }

            // Check if the child process has exited
            if (WIFEXITED(status)) {
                printf("Child process has exited\n");
                break;
            }

            // Retrieve the register state of the child process
            ptrace(PTRACE_GETREGS, pid, 0, &regs);

            // Access the system call number from the register state
            syscall_number = regs.orig_rax;
            map_syscall_to_name(syscall_number, &regs);
            printf("\n");

            // Continue tracing the child process
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
        }

        ptrace(PTRACE_DETACH, pid, 0, 0);
    }

    for (int i = 0; i < newArgc; i++) {
        free(newArgv[i]);
    }
    free(newArgv);
    return 0;
}
