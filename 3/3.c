/*
============================================================================
Name : 3.c
Author : Harsh Jain
Description : Write a C, Ansi-style program to create a file using creat()
              system call and print its file descriptor.
Date : 14th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // create file with rw-r--r-- permissions
    fd = creat("myfile.txt", 0644);

    if (fd < 0) {
        perror("creat");
        return 1;
    }

    printf("File created successfully. File Descriptor: %d\n", fd);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

harshjain@lima-default:~/ss_hol-1/2$ cd ..
harshjain@lima-default:~/ss_hol-1$ mkdir 3
harshjain@lima-default:~/ss_hol-1$ cd 3
harshjain@lima-default:~/ss_hol-1/3$ touch 3.c
harshjain@lima-default:~/ss_hol-1/3$ gcc 3.c
harshjain@lima-default:~/ss_hol-1/3$ ./a.out
File created successfully. File Descriptor: 3
harshjain@lima-default:~/ss_hol-1/3$ ls -l
total 20
-rwxrwxrwx 1 harshjain harshjain  1212 Sep 14 13:22 3.c
-rwxrwxrwx 1 harshjain harshjain 16088 Sep 14 13:22 a.out
-rwxrwxrwx 1 harshjain harshjain     0 Sep 14 13:23 myfile.txt
harshjain@lima-default:~/ss_hol-1/3$
============================================================================
*/

