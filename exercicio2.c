#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Inicializar a variavel global
int var_global = 10;

int main() {
    pid_t pid;

    // Impressao do valor da variavel global antes do fork
    printf("Valor da variavel global antes do fork: %d\n", var_global);

    // Criacao do processo filho
    pid = fork();

    if (pid < 0) {
        // Erro ao criar o processo filho
        fprintf(stderr, "Erro ao criar o processo filho\n");
        return 1;
    } else if (pid == 0) {
        // Codigo executado pelo processo filho
        printf("Eu sou o filho. Meu PID e' %d. Valor da variavel global: %d\n", getpid(), var_global);
    } else {
        // Código executado pelo processo pai
        printf("Eu sou o pai. Meu PID e' %d. Valor da variavel global: %d\n", getpid(), var_global);
    }

    return 0;
}

