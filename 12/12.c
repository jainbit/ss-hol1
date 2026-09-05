/*
============================================================================
Name        : 12.c
Author      : Harsh Jain
Description : Get the opening mode of a file using fcntl() (simple version).
Date : 16th Sep, 2026.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("mode.txt", O_RDWR | O_CREAT, 0644);
    int flags = fcntl(fd, F_GETFL);

    if ((flags & O_ACCMODE) == O_RDONLY) 
        printf("Read Only\n");
    else if ((flags & O_ACCMODE) == O_WRONLY) 
        printf("Write Only\n");
    else 
        printf("Read & Write\n");

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

harshjain@lima-default:~/ss_hol-1$ cd 12
harshjain@lima-default:~/ss_hol-1/12$ vim 12.c
harshjain@lima-default:~/ss_hol-1/12$ gcc 12.c
harshjain@lima-default:~/ss_hol-1/12$ ./a.out
Read & Write

============================================================================
*/

