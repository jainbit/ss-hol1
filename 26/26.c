/*
============================================================================
Name        : 26.c
Author      : Harsh Jain
Description : Execute an external executable with arguments using execlp().
Date : 19th Sep, 2026.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Parent PID = %d: Executing ls -l /tmp\n", getpid());

    // Execute "ls -l /tmp"
    execlp("ls", "ls", "-l", "/tmp", NULL);

    // If execlp returns, it must have failed
    perror("execlp");
    return 1;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
harshjain@lima-default:~/ss_hol-1$ cd 26
harshjain@lima-default:~/ss_hol-1/26$ vim 26.c
harshjain@lima-default:~/ss_hol-1/26$ gcc 26.c
harshjain@lima-default:~/ss_hol-1/26$ ./a.out
Parent PID = 357086: Executing ls -l /tmp
total 0
srwxrwxr-x 1 harshjain harshjain  0 Sep 19 11:15 code-651c50ca-79ac-4977-80d9-3817daa4e251
srwxrwxr-x 1 harshjain harshjain  0 Sep 21 17:40 code-6a5b4b77-d935-4276-bec3-0d12d564bc62
srwxrwxr-x 1 harshjain harshjain  0 Sep 21 17:40 code-ab5006df-9b3e-410c-b079-6353865ac0d2
srwxrwxr-x 1 harshjain harshjain  0 Sep 21 17:40 code-bccc49c8-7225-4c41-b88b-cf2ce8fa8ca5
drwx------ 2 harshjain harshjain 60 Sep 21 17:40 mcp-7OM1lL
drwx------ 2 harshjain harshjain 40 Sep 19 15:41 mcp-rhQU1k
drwxrwxr-x 4 harshjain harshjain 80 Sep 19 16:25 node-compile-cache
drwx------ 2 root      root      40 Sep 19 11:09 snap-private-tmp
drwx------ 3 root      root      60 Sep 19 11:16 systemd-private-e609f7b45e8b4aca92bb1c31e0c24535-ModemManager.service-BL09ci
drwx------ 3 root      root      60 Sep 19 11:14 systemd-private-e609f7b45e8b4aca92bb1c31e0c24535-chrony.service-slgbks
drwx------ 3 root      root      60 Sep 19 11:16 systemd-private-e609f7b45e8b4aca92bb1c31e0c24535-polkit.service-EA3NeY
drwx------ 3 root      root      60 Sep 19 11:09 systemd-private-e609f7b45e8b4aca92bb1c31e0c24535-systemd-logind.service-9tgr39
harshjain@lima-default:~/ss_hol-1/26$
============================================================================
*/

