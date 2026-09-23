/*
============================================================================
Name : 1.c
Author : Harsh Jain
Description : Write a C, Ansi-style program to create 
              a. Soft link 
              b. Hard link 
              c. FIFO
Date : 14th Sep, 2026.
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>

int main() {
    symlink("f1.txt", "softlink_f1");   // create soft link
    link("f1.txt", "hardlink_f1");      // create hard link
    mkfifo("myfifo", 0666);             // create FIFO
    return 0;
}

/*
============================================================================
Sample Output :
----------------------------------------------------------------------------

harshjain@lima-default:~/ss_hol-1$ mkdir 1
harshjain@lima-default:~/ss_hol-1$ cd 1
harshjain@lima-default:~/ss_hol-1/1$ touch 1.c
harshjain@lima-default:~/ss_hol-1/1$ touch f1.txt
harshjain@lima-default:~/ss_hol-1/1$ gcc 1.c
harshjain@lima-default:~/ss_hol-1/1$ ./a.out
harshjain@lima-default:~/ss_hol-1/1$ ls -l
total 36
-rw-rw-r-- 1 harshjain harshjain  1766 Sep 22 16:46 1.c
-rw-rw-r-- 1 harshjain harshjain 16024 Sep 19 04:23 1.out
-rwxrwxr-x 1 harshjain harshjain 70512 Sep 21 17:51 a.out
-rw-rw-r-- 2 harshjain harshjain     0 Sep 19 04:23 f1.txt
-rw-rw-r-- 2 harshjain harshjain     0 Sep 19 04:23 hardlink_f1
prw-rw-r-- 1 harshjain harshjain     0 Sep 19 04:40 myfifo
-rw-rw-r-- 1 harshjain harshjain     0 Sep 19 04:23 softlink_f1

# Equivalent Linux commands:
harshjain@lima-default:~/ss_hol-1/1$ ln -s f1.txt softlink_f1
harshjain@lima-default:~/ss_hol-1/1$ ln f1.txt hardlink_f1
harshjain@lima-default:~/ss_hol-1/1$ mkfifo myfifo

----------------------------------------------------------------------------

============================================================================
*/


