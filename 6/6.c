/*
============================================================================
Name        : 6.c
Author      : Harsh Jain
Description : Echo program using read() and write() system calls only.
              Keeps echoing multiple lines until Ctrl+D (EOF) is pressed.
Date : 15th Sep, 2026.
============================================================================
*/

#include <unistd.h>  // for read() and write()

int main() {
    char c;

    // Keep reading characters until EOF (Ctrl+D)
    while (read(0, &c, 1) > 0) {
        write(1, &c, 1);  // write each character immediately
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1/5$ cd ..
harshjain@lima-default:~/ss_hol-1$ cd 6
harshjain@lima-default:~/ss_hol-1/6$ touch 6.c
harshjain@lima-default:~/ss_hol-1/6$ gcc 6.c
harshjain@lima-default:~/ss_hol-1/6$ ./a.out
hello jabalpur
hello jabalpur
hello 2nd time
hello 2nd time

============================================================================
*/

