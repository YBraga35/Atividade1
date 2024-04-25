#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Variavel global
int global_var = 20;

int main() {
    pid_t pid;

    // Impressão do valor da variavel global antes do fork
    printf("Valor da variavel global antes do fork: %d\n", global_var);

    // Criacao do processo filho
    pid = fork();

    if (pid < 0) {
        // Erro ao criar o processo filho
        fprintf(stderr, "Erro ao criar o processo filho\n");
        return 1;
    } else if (pid == 0) {
        // Codigo executado pelo processo filho
        printf("Eu sou o filho. Meu PID e' %d.\n", getpid());

        // Espera até que o usuario pressione Enter
        printf("Pressione Enter para ver o valor da variavel global no filho.\n");
        getchar();

        // Imprime o valor da variavel global no processo filho
        printf("Valor da variavel global no filho: %d\n", global_var);
    } else {
        // Código executado pelo processo pai
        printf("Eu sou o pai. Meu PID e' %d.\n", getpid());

        // Altera o valor da variavel global no processo pai
        global_var = 20;
        printf("Valor da variavel global alterado para %d no pai.\n", global_var);
    }

    return 0;
}
