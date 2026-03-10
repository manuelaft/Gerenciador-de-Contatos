#include "contatos.h"
#include <string.h>

// cadastro
void cadastro(struct Contato contatos[], int *total) { // void - sem retorno e sem tipo definido
    if (*total >= 100) {
        printf("Limite de contatos atingido.");
        return;
    }
    printf("\nDigite o nome: ");
    scanf("%49s", contatos[*total].nome);
    printf("Telefone: ");
    scanf("%19s",contatos[*total].telefone);
    printf("E-mail: ");
    scanf("%69s",contatos[*total].email);

    (*total)++;
}

// listar
void listar(const struct Contato contatos[],int total) {
    if (total==0) {
        printf("Nenhum contato cadastrado.");
        return;
    }
    for (int i=0;i<total;i++) {
        printf("\n%s - ",contatos[i].nome);
        printf("%s - ",contatos[i].telefone);
        printf("%s\n",contatos[i].email);
    }
}

// buscar indice
int buscarIndice(const struct Contato contatos[], int total, const char nomeBuscado[]) { // função para achar o indice do contato pelo nome digitado (nomeBuscado)
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, nomeBuscado) == 0) {
            return i; // achou
        }
    }
    return -1; // não achou
}

// busca
void busca(const struct Contato contatos[], int total) { // função para 2) buscar
    if (total==0){
        printf("Nenhum contato cadastrado.");
        return;
    }

    char nomeBuscado[50];

    printf("\nDigite o nome do contato que quer achar: ");
    scanf("%49s",nomeBuscado);

    int index = buscarIndice(contatos,total,nomeBuscado); // chamando a função que acha o índice pelo nome

    if (index==-1) {
        printf("\nContato não encontrado.");
    } else {
        printf("\nContato encontrado: \n");
        printf("Nome: %s\n",contatos[index].nome);
        printf("Telefone: %s\n",contatos[index].telefone);
        printf("E-mail: %s\n",contatos[index].email);
    }
}

// editar Contato
void editarContato(struct Contato *c) {
    printf("\n--- Editar Contato ---\n");
    printf("Novo nome: ");
    scanf("%49s",c->nome);
    printf("Novo telefone: ");
    scanf("%19s",c->telefone);
    printf("Novo e-mail: ");
    scanf("%69s",c->email);
    printf("Contato atualizado com sucesso.");
}

void editar(struct Contato contatos[], int total) {
    if (total == 0) {
        printf("Nenhum contato cadastrado.");
        return;
    }

    char nomeBuscado[50];

    printf("Digite o nome do contato que quer editar: ");
    scanf("%49s", nomeBuscado);

    int index = buscarIndice(contatos, total, nomeBuscado);

    if (index == -1) {
        printf("Contato não encontrado.");
        return;
    }

    editarContato(&contatos[index]); // passa o endereço do contato encontrado
}

// excluir
void excluir(struct Contato contatos[],int *total) {
    if (*total==0) {
        printf("Nenhum contato encontrado.");
        return;
    }
    char nomeBuscado[50];

    printf("Digite o nome do contato que quer excluir: ");
    scanf("%49s",nomeBuscado);

    int index=buscarIndice(contatos, *total,nomeBuscado);

    if(index == -1) {
        printf("Contato não encontrado.");
        return; 
    }
 
    /* "puxar" os contatos para esquerda para preencher o buraco */
    for (int i = index; i < (*total) - 1; i++) {
        contatos[i] = contatos[i + 1];
    }

    (*total)--;
    printf("Contato excluído com sucesso.");
}

// função recursiva
int nomes(const struct Contato contatos[], int total, int n) {
    if (total == 0) {
        return 0;
    }

    int contaAtual = 0;
    if ((int)strlen(contatos[total - 1].nome) > n) {
        contaAtual = 1;
    }

    return contaAtual + nomes(contatos, total - 1, n);
}

// stats
void stats(const struct Contato contatos[], int total) {
    if (total == 0) {
        printf("Nenhum contato cadastrado.");
        return;
    }
    int num;
    printf("Digite um número: ");
    scanf("%d",&num);

    int resultado=nomes(contatos,total,num);
    printf("Quantidade de contatos com nome maior que %d: %d",num,resultado);
}