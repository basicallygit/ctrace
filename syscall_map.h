#ifndef SYSCALL_MAP_H
#define SYSCALL_MAP_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/user.h>

void map_syscall_to_name(long syscall_number, struct user_regs_struct* regs) {
    switch (syscall_number) {
        case 0:
            printf("read(%ld, 0x%lx, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 1:
            printf("write(%ld, 0x%lx, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 2:
            printf("open(%ld, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 3:
            printf("close(%ld)\n", regs->rdi);
            break;
        case 4:
            printf("stat(%ld, 0x%lx)\n", regs->rdi, regs->rsi);
            break;
        case 5:
            printf("fstat(%ld, 0x%lx)\n", regs->rdi, regs->rsi);
            break;
        case 6:
            printf("lstat(0x%lx, 0x%lx)\n", regs->rdi, regs->rsi);
            break;
        case 9:
            printf("mmap(0x%lx, %ld, %ld, %ld, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10, regs->r8, regs->r9);
            break;
        case 10:
            printf("mprotect(0x%lx, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 11:
            printf("munmap(0x%lx, %ld)\n", regs->rdi, regs->rsi);
            break;
        case 12:
            printf("brk()\n");
            break;
        case 16:
            printf("ioctl(%ld, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 17:
            printf("pread64(0x%x, 0x%x, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 21:
            printf("access(0x%lx, %ld)\n", regs->rdi, regs->rsi);
            break;
        case 101:
            printf("ptrace(%ld, %ld, 0x%lx, %ld)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 59:
            printf("execve(0x%lx, 0x%lx, 0x%lx)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 157:
            printf("prctl(%ld, %ld, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10, regs->r9);
            break;
        case 158:
            printf("arch_prctl(0x%lx, %lu, 0x%lx)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 217:
            printf("getdents64(%ld, 0x%lx, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 218:
            printf("set_tid_address(0x%lx)\n", regs->rdi);
            break;
        case 231:
            printf("exit_group(%ld)\n", regs->rdi);
            break;
        case 262:
            printf("newfstatat(%ld, 0x%lx, 0x%lx, %lu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 257:
            printf("openat(%ld, 0x%lx, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 273:
            printf("set_robust_list(0x%lx, %ld)\n", regs->rdi, regs->rsi);
            break;
        case 302:
            printf("prlimit64(%ld, %ld, 0x%lx, 0x%lx)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 318:
            printf("getrandom(0x%lx, %ld, %ld)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 332:
            printf("statx()\n");
            break;
        case 334:
            printf("rseq()\n");
            break;
        default:
            printf("syscall number: %d\n", syscall_number);
            break;
    }
}

#endif
