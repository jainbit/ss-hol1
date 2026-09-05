/*
============================================================================
Name        : 29.c
Author      : Harsh Jain
Description : Get and set scheduling policy using sched_getscheduler() and sched_setscheduler().
Date : 19th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main() {
    pid_t pid = getpid();

    // Get current scheduling policy
    int policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy of PID %d: ", pid);
    if (policy == SCHED_OTHER) printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO) printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR) printf("SCHED_RR\n");
    else printf("Unknown\n");

    // Set new scheduling policy (SCHED_RR) with priority 10
    struct sched_param param;
    param.sched_priority = 10;
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
    } else {
        printf("Scheduling policy changed to SCHED_RR with priority 10\n");
    }

    // Get updated scheduling policy
    policy = sched_getscheduler(pid);
    printf("Updated scheduling policy of PID %d: ", pid);
    if (policy == SCHED_OTHER) printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO) printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR) printf("SCHED_RR\n");
    else printf("Unknown\n");

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1/29$ vim 29.c
harshjain@lima-default:~/ss_hol-1/29$ gcc 29.c
harshjain@lima-default:~/ss_hol-1/29$ ./a.out
Current scheduling policy of PID 357441: SCHED_OTHER
sched_setscheduler: Operation not permitted
Updated scheduling policy of PID 357441: SCHED_OTHER
harshjain@lima-default:~/ss_hol-1/29$
============================================================================
*/


