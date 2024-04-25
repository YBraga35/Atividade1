#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_FORKS 9 // 2^9 = 512

int main() {
    int i;
    
    for (i = 0; i < NUM_FORKS; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Erro ao criar o processo filho
            fprintf(stderr, "Erro ao criar o processo filho\n");
            return 1;
        } else if (pid == 0) {
            // Codigo executado pelo processo filho
            printf("Estou vivo!\n");
            sleep(20); // Dorme por 20 segundos
            exit(0);
        }
        
        // Codigo executado pelo processo pai
        // Espera pelo termino do processo filho
        wait(NULL);
    }

    return 0;
}
