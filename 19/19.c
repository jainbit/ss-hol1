/*
============================================================================
Name        : 19.c
Author      : Harsh Jain
Description : Print PID and measure time using CPU TSC (RDTSC).
Date : 17th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc(){
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    uint64_t start = rdtsc();
    // Simple operation to see time elapsed
    for (volatile int i = 0; i < 1000000; i++);
    uint64_t end = rdtsc();

    printf("CPU cycles elapsed: %lu\n", end - start);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

harshjain@lima-default:~/ss_hol-1$ cd 19
harshjain@lima-default:~/ss_hol-1/19$ vim 19.c
harshjain@lima-default:~/ss_hol-1/19$ gcc 19.c
harshjain@lima-default:~/ss_hol-1/19$ ./a.out
Process ID: 906
CPU cycles elapsed: 1584479
harshjain@lima-default:~/ss_hol-1/19$
============================================================================
*/

