#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    // Para ter o valor de retorno dos pids usa-se a atribuição do processo fork
    pid = fork(); 

    if (pid < 0) {
        // Se houve rrro ao criar o processo filho, executa aqui
        fprintf(stderr, "Erro ao criar o processo filho\n");
        return 1;
    } else if (pid == 0) {
        // Codigo executado pelo processo filho
        printf("Eu sou o filho. Meu PID é %d\n", getpid());
    } else {
        // Codigo executado pelo processo pai
        printf("Eu sou o pai. Meu PID é %d\n", getpid());
    }
}
