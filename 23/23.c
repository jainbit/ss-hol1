/*
============================================================================
Name        : 23.c
Author      : Harsh Jain
Description : Create a zombie process.
Date : 18th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process exiting. PID = %d\n", getpid());
        exit(0); // Child exits immediately → becomes zombie
    } else {
        // Parent process sleeps to keep child zombie
        printf("Parent process sleeping. PID = %d\n", getpid());
        sleep(30); // Check zombie using `ps -l`
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

# Run the program in one terminal:
./a.out
Parent process sleeping. PID = 356307
Child process exiting. PID = 356308

# In another terminal, check zombie:
ps -l | grep 23
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S   501  356591  353701  0  80   0 -  2273 do_wai pts/1    00:00:00 bash
4 R   501  356654  356591 99  80   0 -  2447 -      pts/1    00:00:00 ps
 terminal 1
 harshjain@lima-default:~/ss_hol-1/23$ ./a.out
Parent process sleeping. PID = 389274
Child process exiting. PID = 389275

terminal 2
harshjain@lima-default:~/ss_hol-1/23$ ps -p 389275 -o pid,ppid,stat
e,cmd (child id) also /proc/status
    PID    PPID S CMD
 389275  389274 Z [a.out] <defunct>

============================================================================
*/

