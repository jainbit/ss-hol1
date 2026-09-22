/*
============================================================================
Name        : 15.c
Author      : Harsh Jain
Description : Print all environment variables using extern char **environ.
Date : 16th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    for (char **p = environ; *p; ++p)
        puts(*p);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ mkdir 15
harshjain@lima-default:~/ss_hol-1$ cd 15
harshjain@lima-default:~/ss_hol-1/15$ touch 15.c
harshjain@lima-default:~/ss_hol-1/15$ gcc 15.c
harshjain@lima-default:~/ss_hol-1/15$ ./a.out

============================================================================
*/

