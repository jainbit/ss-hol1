/*
============================================================================
Name : 2.c
Author : Harsh Jain
Description : Write a C, Ansi-style program to create an 
              infinite background process and inspect it using /proc.
Date : 19th Sep, 2026
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
[1] 33570

# Inspect process details from /proc
harshjain@lima-default:~/ss_hol-1/2$ cat /proc/33570/status
Name:   a.out
Umask:  0002
State:  S (sleeping)
Tgid:   33570
Pid:    33570
PPid:   32519
TracerPid:      0
Uid:    501     501     501     501
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 999 1000
...
Threads:        1
VmSize:     3228 kB
VmRSS:      1356 kB
...

# Check command line
harshjain@lima-default:~/ss_hol-1/2$ cat /proc/33570/cmdline
./a.out

# Kill the background process
harshjain@lima-default:~/ss_hol-1/2$ kill 33570

----------------------------------------------------------------------------

============================================================================
*/