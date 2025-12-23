#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

// This program synchronizes two threads using semaphores and a mutex,
// ensuring mutual exclusion on a shared resource and alternating access.

sem_t s1, s2, mutex;

// Definition of functions
void buyPasta() {
    // Implementation of the buyPasta function
}

void buyPesto() {
    // Implementation of the buyPesto function
}

void eatDinner() {
    // Implementation of the eatDinner function
}

void *A(void *arg) {
    buyPasta();
    printf("buy1 done\n");

    sem_wait(&s1);
    sem_wait(&mutex);

    eatDinner();
    printf("p1 entered shared resource\n");

    sem_post(&mutex);
    sem_post(&s2);

    pthread_exit(NULL);
}

void *B(void *arg) {
    buyPesto();
    printf("buy2 done\n");

    sem_wait(&s2);
    sem_wait(&mutex);

    eatDinner();
    printf("p2 entered shared resource\n");

    sem_post(&mutex);
    sem_post(&s1);

    pthread_exit(NULL);
}

int main() {
    // Initialize semaphores
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    sem_init(&mutex, 0, 1);

    // Create threads A and B
    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, A, NULL);
    pthread_create(&threadB, NULL, B, NULL);

    // Wait for threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    // Destroy semaphores
    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&mutex);

    return 0;
}
