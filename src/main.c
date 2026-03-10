#include <stdio.h>
#include <string.h>
#include "contatos.h"

int main()
{
    struct Contato contatos[100];
    int total=0, option;

    do {
        printf("\nGERENCIADOR DE CONTATOS\n");
        printf("[ 1 ] Cadastrar\n");
        printf("[ 2 ] Listar\n");
        printf("[ 3 ] Buscar por nome\n");
        printf("[ 4 ] Editar\n");
        printf("[ 5 ] Excluir\n");
        printf("[ 6 ] Estatísticas\n");
        printf("[ 7 ] Sair\n");
        printf("Sua opção: ");
        scanf("%d", &option);

        if (option == 1) {
            cadastro(contatos, &total);
        } else if (option==2) {
            listar(contatos,total);
        } else if (option==3) {
            busca(contatos,total);
        } else if (option==4) {
            editar(contatos,total);
        } else if (option==5) {
            excluir(contatos,&total);
        } else if (option == 6) {
            stats(contatos,total);
        }

    } while(option!=7);
    
    if (option == 7) {
        printf("\nEncerrando o programa...");
        return 0;
    }

    return 0;
}