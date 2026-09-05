/*
============================================================================
Name        : 27.c
Author      : Harsh Jain
Description : Execute 'ls -Rl' using different exec* variants.
Date : 19th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Parent PID = %d: Executing 'ls -Rl'\n", getpid());

    // Using execl
    printf("\n--- Using execl ---\n");
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl");  // If exec fails
        exit(1);
    }
    wait(NULL);

    // Using execlp
    printf("\n--- Using execlp ---\n");
    if (fork() == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp");
        exit(1);
    }
    wait(NULL);

    // Using execv
    printf("\n--- Using execv ---\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
        perror("execv");
        exit(1);
    }
    wait(NULL);

    // Using execvp
    printf("\n--- Using execvp ---\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
        perror("execvp");
        exit(1);
    }
    wait(NULL);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
Parent PID = 357276: Executing 'ls -Rl'

--- Using execl ---
.:
total 20
-rw-rw-r-- 1 harshjain harshjain  2194 Sep 19 04:23 27.c
-rwxrwxr-x 1 harshjain harshjain 71016 Sep 21 18:12 a.out

--- Using execlp ---
.:
total 20
-rw-rw-r-- 1 harshjain harshjain  2194 Sep 19 04:23 27.c
-rwxrwxr-x 1 harshjain harshjain 71016 Sep 21 18:12 a.out

--- Using execv ---
.:
total 20
-rw-rw-r-- 1 harshjain harshjain  2194 Sep 19 04:23 27.c
-rwxrwxr-x 1 harshjain harshjain 71016 Sep 21 18:12 a.out

--- Using execvp ---
.:
total 20
-rw-rw-r-- 1 harshjain harshjain  2194 Sep 19 04:23 27.c
-rwxrwxr-x 1 harshjain harshjain 71016 Sep 21 18:12 a.out
harshjain@lima-default:~/ss_hol-1/27$ 
============================================================================
*/

