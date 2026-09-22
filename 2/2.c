/*
============================================================================
Name : 2.c
Author : Harsh Jain
Description : Write a C, Ansi-style program to create an 
              infinite background process and inspect it using /proc.
Date : 14th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {
        printf("Running process with PID: %d\n", getpid());
        sleep(8);   // sleep to avoid flooding the terminal
    }
    return 0;
}

/*
============================================================================
Sample Output :
----------------------------------------------------------------------------

# Compile
harshjain@lima-default:~/ss_hol-1/2$ gcc 2.c

# Run as background process
harshjain@lima-default:~/ss_hol-1/2$ ./a.out &
[1] 587

# Inspect process details from /proc
harshjain@lima-default:~/ss_hol-1/2$ cat /proc/362912/status
Name:   a.out
Umask:  0002
State:  S (sleeping)
Tgid:   362912
Ngid:   0
Pid:    362912
PPid:   362159~
...

# Check command line
harshjain@lima-default:~/ss_hol-1/2$ cat /proc/362912/cmdline
./a.out

# Kill the background process
harshjain@lima-default:~/ss_hol-1/2$ kill 362912

----------------------------------------------------------------------------

============================================================================
*/

