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
harshjain@lima-default:~/ss_hol-1/1$ vim 1.c
harshjain@lima-default:~/ss_hol-1/1$ touch f1.txt
harshjain@lima-default:~/ss_hol-1/1$ gcc 1.c
harshjain@lima-default:~/ss_hol-1/1$ ./a.out
harshjain@lima-default:~/ss_hol-1/1$ ls -l
total 20
-rwxrwxrwx 1 harshjain harshjain  1396 Sep 14 13:10 1.c
-rwxrwxrwx 1 harshjain harshjain 16024 Sep 14 13:10 a.out
-rwxrwxrwx 2 harshjain harshjain     0 Sep 14 13:10 f1.txt
-rwxrwxrwx 2 harshjain harshjain     0 Sep 14 13:10 hardlink_f1
lrwxrwxrwx 1 harshjain harshjain     6 Sep 14 13:11 softlink_f1 -> f1.txt

# Equivalent Linux commands:
harshjain@lima-default:~/ss_hol-1/1$ ln -s f1.txt softlink_f1
harshjain@lima-default:~/ss_hol-1/1$ ln f1.txt hardlink_f1
harshjain@lima-default:~/ss_hol-1/1$ mkfifo myfifo

----------------------------------------------------------------------------

============================================================================
*/


