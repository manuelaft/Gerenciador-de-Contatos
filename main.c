#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[20];
    char email[70];
}; 

void cadastro(struct Contato contatos[], int total) { // void - sem retorno e sem tipo definido
    printf("\nDigite o nome: ");
    scanf("%49s", contatos[total].nome);
    printf("Telefone: ");
    scanf("%19s",contatos[total].telefone);
    printf("E-mail: ");
    scanf("%69s",contatos[total].email);
}

void listar(struct Contato contatos[],int total) {
    if (total==0) {
        printf("Nenhum contato cadastrado.");
        return;
    }
    for (int i=0;i<total;i++) {
        printf("\n%s\n",contatos[i].nome);
        printf("%s\n",contatos[i].telefone);
        printf("%s\n",contatos[i].email);
    }
}

void busca() {

}

void editar() {

}

void excluir() {

}

void stats() {

}

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
            cadastro(contatos, total);
            total++;
        } else if (option==2) {
            listar(contatos,total);
        }

    } while(option!=7);
    
    if (option == 7) {
        printf("Encerrando o programa...");
        return 0;
    }

    
    return 0;
}