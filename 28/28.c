/*
============================================================================
Name        : 28.c
Author      : Harsh Jain
Description : Get min and max real-time priority for SCHED_FIFO and SCHED_RR.
Date : 19th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int min_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_fifo = sched_get_priority_max(SCHED_FIFO);

    int min_rr = sched_get_priority_min(SCHED_RR);
    int max_rr = sched_get_priority_max(SCHED_RR);

    printf("SCHED_FIFO: min priority = %d, max priority = %d\n", min_fifo, max_fifo);
    printf("SCHED_RR  : min priority = %d, max priority = %d\n", min_rr, max_rr);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ mkdir 28
harshjain@lima-default:~/ss_hol-1$ cd 28
harshjain@lima-default:~/ss_hol-1/28$ vim 28.c
harshjain@lima-default:~/ss_hol-1/28$ gcc 28.c
harshjain@lima-default:~/ss_hol-1/28$ ./a.out
SCHED_FIFO: min priority = 1, max priority = 99
SCHED_RR  : min priority = 1, max priority = 99
============================================================================
*/

