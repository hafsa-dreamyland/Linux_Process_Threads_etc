/*Process IDs are 16-bit numbers that are assigned sequentially by Linux as new processes are created.
Every process also has a parent process (except the special init process). Thus, you can think of the 
processes on a Linux system as arranged in a tree, with the init process at its root.
The parent process ID, or ppid, is simply the process ID of the process’s parent.
When referring to process IDs in a C or C++ program, always use the pid_t typedef, 
which is defined in <sys/types.h>.
A program can obtain the process ID of the process it’s running in with the getpid() system call, 
and it can obtain the process ID of its parent process with the getppid() system call.*/

#include <stdio.h>
#include <unistd.h>
int main() {
    printf("The Process ID is %d\n", (int) getpid());
    printf("The parent process ID si %d\n", (int) getppid());
    return 0; 
}