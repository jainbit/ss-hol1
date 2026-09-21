/*
============================================================================
Name        : 25.c
Author      : Harsh Jain
Description : Wait for a particular child using waitpid().
Date : 18th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("fork");
        return 1;
    } else if (pid1 == 0) {
        // First child
        printf("First child started. PID = %d\n", getpid());
        sleep(3);
        printf("First child exiting. PID = %d\n", getpid());
        exit(1);
    }

    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("fork");
        return 1;
    } else if (pid2 == 0) {
        // Second child
        printf("Second child started. PID = %d\n", getpid());
        sleep(5);
        printf("Second child exiting. PID = %d\n", getpid());
        exit(2);
    }

    // Parent process
    int status;
    printf("Parent waiting for first child: PID = %d\n", pid1);
    waitpid(pid1, &status, 0);  // Wait specifically for first child
    if (WIFEXITED(status))
        printf("First child exited with status %d\n", WEXITSTATUS(status));

    printf("Parent now waiting for second child: PID = %d\n", pid2);
    waitpid(pid2, &status, 0);  // Wait specifically for second child
    if (WIFEXITED(status))
        printf("Second child exited with status %d\n", WEXITSTATUS(status));

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ mkdir 25
harshjain@lima-default:~/ss_hol-1$ cd 25
harshjain@lima-default:~/ss_hol-1/25$ vim 25.c
harshjain@lima-default:~/ss_hol-1/25$ gcc 25.c
harshjain@lima-default:~/ss_hol-1/25$ ./a.out
First child started. PID = 356959
Parent waiting for first child: PID = 356959
Second child started. PID = 356960

First child exiting. PID = 356959
First child exited with status 1
Parent now waiting for second child: PID = 356960
Second child exiting. PID = 356960
Second child exited with status 2
harshjain@lima-default:~/ss_hol-1/25$ 
============================================================================
*/

