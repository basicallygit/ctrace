#ifndef SYSCALL_MAP_H
#define SYSCALL_MAP_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/user.h>

void map_syscall_to_name(long syscall_number, struct user_regs_struct* regs) {
    switch (syscall_number) {
        case 0:
            printf("read(%llu, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 1:
            printf("write(%llu, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 2:
            printf("open(%llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 3:
            printf("close(%llu)\n", regs->rdi);
            break;
        case 4:
            printf("stat(%llu, 0x%llx)\n", regs->rdi, regs->rsi);
            break;
        case 5:
            printf("fstat(%llu, 0x%llx)\n", regs->rdi, regs->rsi);
            break;
        case 6:
            printf("lstat(0x%llx, 0x%llx)\n", regs->rdi, regs->rsi);
            break;
        case 7:
            printf("poll(0x%llx, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 8:
            printf("lseek(%llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 9:
            printf("mmap(0x%llx, %llu, %llu, %llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10, regs->r8, regs->r9);
            break;
        case 10:
            printf("mprotect(0x%llx, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 11:
            printf("munmap(0x%llx, %llu)\n", regs->rdi, regs->rsi);
            break;
        case 12:
            printf("brk()\n");
            break;
        case 13:
            printf("rt_sigaction(%llu, 0x%llx, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 14:
            printf("rt_sigprocmask(%llu, 0x%llx, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 15:
            printf("rt_sigreturn(%llu)\n", regs->rdi);
            break;
        case 16:
            printf("ioctl(%llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 17:
            printf("pread64(%llu, 0x%llx, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 18:
            printf("pwrite64(%llu, 0x%llx, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 19:
            printf("readv(%llu, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 20:
            printf("writev(%llu, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 21:
            printf("access(0x%llx, %llu)\n", regs->rdi, regs->rsi);
            break;
        case 22:
            printf("pipe(0x%llx)\n", regs->rdi);
            break;
        case 23:
            printf("select(%llu, 0x%llx, 0x%llx, 0x%llx, 0x%llx)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10, regs->r8);
            break;
        case 24:
            printf("sched_yield()\n");
            break;
        case 25:
            printf("mremap(0x%llx, %llu, %llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10, regs->r8);
            break;
        case 26:
            printf("msync(%llu, %llu, %llu)", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 27:
            printf("mincore(%llu, %llu, 0x%llx)", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 28:
            printf("madvise(%llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 101:
            printf("ptrace(%llu, %llu, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 59:
            printf("execve(0x%llx, 0x%llx, 0x%llx)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 157:
            printf("prctl(%llu, %llu, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 158:
            printf("arch_prctl(0x%llx, %llu, 0x%llx)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 217:
            printf("getdents64(%llu, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 218:
            printf("set_tid_address(0x%llx)\n", regs->rdi);
            break;
        case 231:
            printf("exit_group(%llu)\n", regs->rdi);
            break;
        case 262:
            printf("newfstatat(%llu, 0x%llx, 0x%llx, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 257:
            printf("openat(%llu, 0x%llx, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 273:
            printf("set_robust_list(0x%llx, %llu)\n", regs->rdi, regs->rsi);
            break;
        case 302:
            printf("prlimit64(%llu, %llu, 0x%llx, 0x%llx)\n", regs->rdi, regs->rsi, regs->rdx, regs->r10);
            break;
        case 318:
            printf("getrandom(0x%llx, %llu, %llu)\n", regs->rdi, regs->rsi, regs->rdx);
            break;
        case 332:
            printf("statx()\n");
            break;
        case 334:
            printf("rseq()\n");
            break;
        default:
            printf("syscall number: %ld\n", syscall_number);
            break;
    }
}

#endif
