/*
============================================================================
Name : 5.c
Author : Harsh Jain
Description : Write a program to create five new files with infinite loop.
              Execute the program in the background and check the file
              descriptor table at /proc/pid/fd.
Date : 17th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];
    int count = 0;
    char filename[50];

    while (1) {
        for (int i = 0; i < 5; i++) {
            sprintf(filename, "file_%d_%d.txt", count, i);

            fd[i] = open(filename, O_CREAT | O_RDWR, 0644);

            if (fd[i] < 0) {
                perror("open");
                return 1;
            }

            printf("Created %s with FD: %d\n", filename, fd[i]);
        }

        count++;
        sleep(5);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

# Compile the program

harshjain@lima-default:~/ss_hol-1$ mkdir 5
harshjain@lima-default:~/ss_hol-1$ cd 5
harshjain@lima-default:~/ss_hol-1/5$ touch 5.c
harshjain@lima-default:~/ss_hol-1/5$ gcc 5.c
harshjain@lima-default:~/ss_hol-1/5$ ./a.out &
[1] 366892
Created file_0_0.txt with FD: 3
Created file_0_1.txt with FD: 4
Created file_0_2.txt with FD: 5
Created file_0_3.txt with FD: 6
Created file_0_4.txt with FD: 7
harshjain@lima-default:~/ss_hol-1/5$ Created file_1_0.txt with FD: 8

Created file_1_0.txt with FD: 8
Created file_1_1.txt with FD: 9
Created file_1_2.txt with FD: 10
Created file_1_3.txt with FD: 11
Created file_1_4.txt with FD: 12

# Check the process ID

harshjain@lima-default:~/ss_hol-1/5$ echo $! 366892
366892

# Check the file descriptor table



total 0
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 0 -> /dev/pts/1
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 1 -> /dev/pts/1
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 2 -> /dev/pts/1
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 3 -> /home/harshjain.guest/ss_hol-1/5/file_0_0.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 4 -> /home/harshjain.guest/ss_hol-1/5/file_0_1.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 5 -> /home/harshjain.guest/ss_hol-1/5/file_0_2.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 6 -> /home/harshjain.guest/ss_hol-1/5/file_0_3.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 7 -> /home/harshjain.guest/ss_hol-1/5/file_0_4.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 8 -> /home/harshjain.guest/ss_hol-1/5/file_1_0.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 9 -> /home/harshjain.guest/ss_hol-1/5/file_1_1.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 10 -> /home/harshjain.guest/ss_hol-1/5/file_1_2.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 11 -> /home/harshjain.guest/ss_hol-1/5/file_1_3.txt
lrwx------ 1 harshjain harshjain 64 Sep 22 16:09 12 -> /home/harshjain.guest/ss_hol-1/5/file_1_4.txt

# Stop the background process

harshjain@lima-default:~/ss_hol-1/5$ kill 366892

[1]+  Terminated              ./a.out

----------------------------------------------------------------------------
============================================================================
*/