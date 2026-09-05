/*
============================================================================
Name        : 10.c
Author      : Harsh Jain
Description : Create a hole in a file using lseek().
Date : 15th Sep, 2026.
============================================================================
*/

#include <unistd.h>   // for write(), lseek(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

int main() {
    int fd;
    
    // Open file for writing (create if it doesn't exist)
    fd = open("hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write some initial data
    write(fd, "Hello", 5);

    // Move file pointer 10 bytes ahead (creates a hole)
    lseek(fd, 10, SEEK_CUR);

    // Write more data after the hole
    write(fd, "World", 5);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ cd 10
harshjain@lima-default:~/ss_hol-1/10$ vim 10.c
harshjain@lima-default:~/ss_hol-1/10$ gcc 10.c
harshjain@lima-default:~/ss_hol-1/10$ ./a.out
harshjain@lima-default:~/ss_hol-1/10$ ls -l hole.txt
-rwxrwxrwx 1 harshjain harshjain 20 Sep 15 13:52 hole.txt
harshjain@lima-default:~/ss_hol-1/10$ od -c hole.txt
0000000   H   e   l   l   o  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0   W
0000020   o   r   l   d
0000024
harshjain@lima-default:~/ss_hol-1/10$
============================================================================
*/

