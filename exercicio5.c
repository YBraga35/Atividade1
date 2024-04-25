#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <programa>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        // Erro ao criar o processo filho
        fprintf(stderr, "Erro ao criar o processo filho\n");
        return 1;
    } else if (pid == 0) {
        // Codigo executado pelo processo filho
        execl(argv[1], argv[1], NULL);
        // Se execl retornar, houve um erro
        fprintf(stderr, "Erro ao executar %s\n", argv[1]);
        exit(1);
    } else {
        // Codigo executado pelo processo pai
        wait(NULL); // Espera pelo trrmino do processo filho
        printf("Processo pai terminou a execucao.\n");
    }

    return 0;
}
