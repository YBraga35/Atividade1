#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int nfilho;

void proc_filho() {
    printf("Processo FILHO %d iniciado\n", nfilho);
    printf("Vai dormir por %d segundos\n", nfilho * 10);
    sleep(nfilho * 10);
    printf("Processo FILHO %d encerrado\n", nfilho);
}

int main() {
    printf("Processo PAI iniciado\n");

    // Criar 4 processos filhos
    for (nfilho = 1; nfilho <= 4; nfilho++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Erro ao criar o processo filho
            fprintf(stderr, "Erro ao criar o processo filho\n");
            return 1;
        } else if (pid == 0) {
            // Codigo executado pelo processo filho
            proc_filho();
            exit(0);
        } else {
            // Espera pelo termino do processo filho atual
            wait(NULL);
            // Sai do loop para evitar criar mais processos filhos
            break;
        }
    }

    // Codigo executado pelo processo pai apos a criacao dos 4 processos filhos
    printf("Processo PAI encerrado\n");

    return 0;
}
