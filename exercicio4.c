#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Funcao para imprimir os primeiros N numeros pares
void imprimirNumerosPares(int n) {
    int i;
    for (i = 2; i <= 2 * n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;

    // Solicitar ao usuario que insira o valor de N
    printf("Digite a quantidade de numeros pares a serem impressos: ");
    scanf("%d", &n);

    // Criando o processo filho
    pid_t pid = fork();

    if (pid < 0) {
        // Erro ao criar o processo filho
        fprintf(stderr, "Erro ao criar o processo filho\n");
        return 1;
    } else if (pid == 0) {
        // Codigo executado pelo processo filho
        imprimirNumerosPares(n);
    } else {
        // Codigo executado pelo processo pai
        // Espera pelo termino do processo filho
        wait(NULL);
        printf("Processo pai terminou a execucao.\n");
    }

    return 0;
}
