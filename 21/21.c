/*
============================================================================
Name        : 21.c
Author      : Harsh Jain
Description : Simple fork example to print parent and child PIDs.
Date : 18th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ mkdir 21
harshjain@lima-default:~/ss_hol-1$ cd 21
harshjain@lima-default:~/ss_hol-1/21$ vim 21.c
harshjain@lima-default:~/ss_hol-1/21$ gcc 21.c
harshjain@lima-default:~/ss_hol-1/21$ ./a.out
Parent process: PID = 356059, Child PID = 356060
Child process: PID = 356060, Parent PID = 356059
============================================================================
*/

