/*
============================================================================
Name : 1.c
Author : Harsh Jain
Description : Write a C, Ansi-style program to create
              a. Soft link
              b. Hard link
              c. FIFO
Date : 19th Sep, 2026
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
total 20
-rw-rw-r-- 1 harshjain harshjain   591 Sep 19 02:56 1.c
-rwxrwxr-x 1 harshjain harshjain 70512 Sep 19 02:57 a.out
-rw-rw-r-- 2 harshjain harshjain     0 Sep 19 02:49 f1.txt
-rw-rw-r-- 2 harshjain harshjain     0 Sep 19 02:49 hardlink_f1
prw-rw-r-- 1 harshjain harshjain     0 Sep 19 02:58 myfifo
lrwxrwxrwx 1 harshjain harshjain     6 Sep 19 02:58 softlink_f1 -> f1.txt
----------------------------------------------------------------------------

============================================================================
*/
