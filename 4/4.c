/*
============================================================================
Name : 4.c
Author : Harsh Jain
Description : Write a C, Ansi-style program to open an existing file in
              read-write mode. Also try to use O_EXCL flag.
Date : 14th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Try to open existing file "myfile.txt" in read-write mode
    fd = open("myfile.txt", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("File opened successfully in read-write mode. FD: %d\n", fd);
    close(fd);

    // Now try opening with O_EXCL along with O_CREAT
    fd = open("myfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd < 0) {
        perror("open with O_EXCL");
    } else {
        printf("File opened with O_EXCL. FD: %d\n", fd);
        close(fd);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

harshjain@lima-default:~/ss_hol-1$ mkdir 4
harshjain@lima-default:~/ss_hol-1$ cd 4
harshjain@lima-default:~/ss_hol-1/4$ touch 4.c
harshjain@lima-default:~/ss_hol-1/4$ gcc 4.c
harshjain@lima-default:~/ss_hol-1/4$ touch myfile.txt
harshjain@lima-default:~/ss_hol-1/4$ ./a.out
File opened successfully in read-write mode. FD: 3
open with O_EXCL: File exists
harshjain@lima-default:~/ss_hol-1/4$ ls -l
total 20
-rwxrwxrwx 1 harshjain harshjain  1350 Sep 14 13:45 4.c
-rwxrwxrwx 1 harshjain harshjain 16088 Sep 14 13:45 a.out
-rw-r--r-- 1 harshjain harshjain     0 Sep 14 13:46 myfile.txt

============================================================================
*/

