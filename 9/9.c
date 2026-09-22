/*
============================================================================
Name        : 9.c
Author      : Harsh Jain
Description : Print file metadata using stat() system call.
Date : 15th Sep, 2026.
============================================================================
*/

#include <sys/stat.h>   // for stat()
#include <unistd.h>     // for close()
#include <stdio.h>      // for printf(), perror()
#include <time.h>       // for ctime()

int main() {
    struct stat fileStat;

    // Get file metadata
    if (stat("f1.txt", &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    // Print file metadata
    printf("File: f1.txt\n");
    printf("File Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Number of Links: %ld\n", (long)fileStat.st_nlink);
    printf("File inode: %ld\n", (long)fileStat.st_ino);
    printf("File Permissions: ");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("Last Access: %s", ctime(&fileStat.st_atime));
    printf("Last Modification: %s", ctime(&fileStat.st_mtime));
    printf("Last Status Change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ mkdir 9
harshjain@lima-default:~/ss_hol-1$ cd 9
harshjain@lima-default:~/ss_hol-1/9$ touch 9.c
harshjain@lima-default:~/ss_hol-1/9$ gcc 9.c
harshjain@lima-default:~/ss_hol-1/9$ ./a.out
stat: No such file or directory
harshjain@lima-default:~/ss_hol-1/9$ touch f1.txt
harshjain@lima-default:~/ss_hol-1/9$ echo "hi this is again f1 for 9th " > f1.txt
harshjain@lima-default:~/ss_hol-1/9$ gcc 9.c
harshjain@lima-default:~/ss_hol-1/9$ ./a.out
File: f1.txt
File Size: 29 bytes
Number of Links: 1
File inode: 788535
File Permissions: -rw-rw-r--
Last Access: Tue Sep 15 13:50:50 2026
Last Modification: Tue Sep 15 13:50:50 2026
Last Status Change: Tue Sep 15 13:50:50 2026
harshjain@lima-default:~/ss_hol-1/9$
============================================================================
*/

