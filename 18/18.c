/*
============================================================================
Name        : 18.c
Author      : Harsh Jain
Description : Record locking example with 3 fixed-size records using fcntl.
Date : 17th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define RECORDS 3

int main() {
    int fd = open("records.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock fl = {0};
    int rec_no;
    printf("Enter record number to lock (0-2): ");
    scanf("%d", &rec_no);

    if (rec_no < 0 || rec_no >= RECORDS) {
        printf("Invalid record number\n");
        close(fd);
        return 1;
    }

    // Set up lock for the specific record
    fl.l_type = F_WRLCK;          // write lock
    fl.l_whence = SEEK_SET;
    fl.l_start = rec_no * sizeof(int);
    fl.l_len = sizeof(int);

    if (fcntl(fd, F_SETLKW, &fl) < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Record %d locked. Writing data...\n", rec_no);

    int data;
    printf("Enter data for record %d: ", rec_no);
    scanf("%d", &data);

    lseek(fd, rec_no * sizeof(int), SEEK_SET);
    write(fd, &data, sizeof(int));

    // Unlock the record
    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    printf("Record %d unlocked.\n", rec_no);
    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ mkdir 18
harshjain@lima-default:~/ss_hol-1$ cd 18
harshjain@lima-default:~/ss_hol-1/18$ vim 18.c
harshjain@lima-default:~/ss_hol-1/18$ gcc 18.c
harshjain@lima-default:~/ss_hol-1/18$ ./a.out
Enter record number to lock (0-2): 1
Record 1 locked. Writing data...
Enter data for record 1: 100
Record 1 unlocked.
harshjain@lima-default:~/ss_hol-1/18$ ./a.out
Enter record number to lock (0-2): 2
Record 2 locked. Writing data...
Enter data for record 2: 43
Record 2 unlocked.
harshjain@lima-default:~/ss_hol-1/18$
============================================================================
*/

