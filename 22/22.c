/*
============================================================================
Name        : 22.c
Author      : Harsh Jain
Description : Parent and child write to the same file using fork().
Date : 18th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("shared.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        write(fd, "Child writing...\n", strlen("Child writing...\n"));
    } else {
        // Parent process
        write(fd, "Parent writing...\n", strlen("Parent writing...\n"));
    }

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

harshjain@lima-default:~/ss_hol-1$ cd 22
harshjain@lima-default:~/ss_hol-1/22$ gcc 22.c
harshjain@lima-default:~/ss_hol-1/22$ ./a.out
harshjain@lima-default:~/ss_hol-1/22$ cat shared.txt
Parent writing...
Child writing...

# Note: Order may vary due to scheduling

============================================================================
*/

