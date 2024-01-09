#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

// ... il resto del tuo codice ...


// Dichiarazione di un semaforo globale
sem_t semaphore;

void fork22() {
    if (fork() == fork()) {
        // Sezione critica protetta dal semaforo
        sem_wait(&semaphore);
        printf("A");
        sem_post(&semaphore);
    } else {
        printf("B");
        // Segnaliamo che è stata stampata almeno un'occorrenza della lettera "B"
        sem_post(&semaphore);
    }
}

int main() {
    // Inizializzazione del semaforo
    sem_init(&semaphore, 0, 0);
    
    fork22();

    // Attendi che tutti i processi completino
    wait(NULL);

    // Deallocazione del semaforo
    sem_destroy(&semaphore);

    return 0;
}
