/*
 * NOTE:
 * This program is intentionally written in a tricky and non-idiomatic way
 * to test understanding of fork(), process creation, and concurrency.
 *
 * The semaphore usage is NOT correct for inter-process synchronization
 * (pshared = 0), and the behavior may be undefined on real systems.
 */

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

/* Global semaphore (used incorrectly on purpose, for exercise only) */
sem_t semaphore;

/*
 * fork22()
 * Calls fork() twice inside a comparison.
 * This creates multiple processes and causes different execution paths.
 */
void fork22() {
    /* Two fork() calls are evaluated and compared */
    if (fork() == fork()) {

        /* Critical section protected by the semaphore */
        sem_wait(&semaphore);
        printf("A");
        sem_post(&semaphore);

    } else {

        /* Print B without synchronization */
        printf("B");

        /* Signal that at least one 'B' has been printed */
        sem_post(&semaphore);
    }
}

int main() {

    /* Initialize the semaphore
     * pshared = 0 means the semaphore is shared between threads,
     * NOT between processes (this is intentional for the exercise)
     */
    sem_init(&semaphore, 0, 0);

    /* Execute the function containing the fork() logic */
    fork22();

    /* Wait for (at least) one child process to terminate */
    wait(NULL);

    /* Destroy the semaphore */
    sem_destroy(&semaphore);

    return 0;
}
