/*
============================================================================
Name        : 20.c
Author      : Harsh Jain
Description : Get and modify process priority using nice().
Date : 17th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();

    // Get current nice value
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority of process %d: %d\n", pid, priority);

    // Increase nice value by 5 (lower priority)
    if (nice(5) == -1) perror("nice");

    // Get new priority
    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of process %d: %d\n", pid, priority);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1/20$ touch 20.c
harshjain@lima-default:~/ss_hol-1/20$ gcc 20.c
harshjain@lima-default:~/ss_hol-1/20$ ./a.out
Current priority of process 378849: 0
New priority of process 378849: 5
============================================================================
*/

