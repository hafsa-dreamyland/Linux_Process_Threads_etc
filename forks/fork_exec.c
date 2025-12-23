#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <unistd.h>

/*
 * spawn()
 * Creates a child process using fork() and executes a new program
 * in the child process using execvp().
 *
 * Returns:
 *   - the child PID to the parent process
 *   - does not return in the child process (unless exec fails)
 */
pid_t spawn(char *program_name, char **arg_list) {
    pid_t child_pid;

    /* Create a new process */
    child_pid = fork();

    if (child_pid > 0) {
        /* Parent process:
         * return the PID of the child
         */
        return child_pid;
    }
    else if (child_pid == 0) {
        /* Child process:
         * replace the current process image with a new program
         */
        execvp(program_name, arg_list);

        /* execvp returns only if an error occurs */
        perror("execvp failed");
        exit(EX_OSERR);
    }
    else {
        /* fork() failed */
        perror("fork failed");
        exit(EX_OSERR);
    }
}

int main(void) {
    pid_t child_pid;
    int child_status;

    /* Argument list for execvp()
     * Must end with NULL
     */
    char *arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    /* Create the child process and run ls -l / */
    child_pid = spawn(arg_list[0], arg_list);

    /* Wait for the specific child process to terminate */
    waitpid(child_pid, &child_status, 0);

    /* Check how the child process terminated */
    if (WIFEXITED(child_status)) {
        printf("The child process exited normally with exit code %d.\n",
               WEXITSTATUS(child_status));
    } else {
        printf("The child process exited abnormally.\n");
    }

    printf("Done with the main program.\n");
    return 0;
}
