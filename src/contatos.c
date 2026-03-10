#include "contatos.h"
#include <string.h>

void lerLinha(char *dest, int tam) {
    if (fgets(dest, tam, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    dest[strcspn(dest, "\n")] = '\0'; // tira o \n
}

int emailValido(const char email[]) {
    const char *arroba = strchr(email, '@');
    if (arroba == NULL) {
        return 0;
    }
    if (strchr(arroba, '.') == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int telefoneValido(const char tel[]) {
    int digitos = 0;
    for (int i = 0; tel[i] != '\0'; i++) {
        if (tel[i] >= '0' && tel[i] <= '9') digitos++;
    }
    return digitos >= 8;
}

// cadastro
void cadastro(struct Contato contatos[], int *total) { // void - sem retorno e sem tipo definido
    if (*total >= 100) {
        printf("Limite de contatos atingido.");
        return;
    }
    printf("\nDigite o nome: ");
    lerLinha(contatos[*total].nome, sizeof(contatos[*total].nome));
    printf("Telefone: ");
    lerLinha(contatos[*total].telefone, sizeof(contatos[*total].telefone));

    while (!telefoneValido(contatos[*total].telefone)) {
        printf("Telefone inválido. Digite novamente: ");
        lerLinha(contatos[*total].telefone, sizeof(contatos[*total].telefone));
    }
    printf("E-mail: ");
    lerLinha(contatos[*total].email, sizeof(contatos[*total].email));

    while (!emailValido(contatos[*total].email)) {
        printf("E-mail inválido. Digite novamente: ");
        lerLinha(contatos[*total].email, sizeof(contatos[*total].email));
    }

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
    lerLinha(nomeBuscado, sizeof(nomeBuscado));
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
    lerLinha(c->nome, sizeof(c->nome));

    printf("Novo telefone: ");
    lerLinha(c->telefone, sizeof(c->telefone));

    while (!telefoneValido(c->telefone)) {
        printf("Telefone inválido. Digite novamente: ");
        lerLinha(c->telefone, sizeof(c->telefone));
    }

    printf("Novo e-mail: ");
    lerLinha(c->email, sizeof(c->email));

    while (!emailValido(c->email)) {
        printf("E-mail inválido. Digite novamente: ");
        lerLinha(c->email, sizeof(c->email));
    }

    printf("Contato atualizado com sucesso.\n");
}

void editar(struct Contato contatos[], int total) {
    if (total == 0) {
        printf("Nenhum contato cadastrado.");
        return;
    }

    char nomeBuscado[50];

    printf("Digite o nome do contato que quer editar: ");
    lerLinha(nomeBuscado, sizeof(nomeBuscado));
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
    lerLinha(nomeBuscado, sizeof(nomeBuscado));
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
    printf("Contato excluído com sucesso.\n");
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
    printf("Quantidade de contatos com nome maior que %d: %d\n",num,resultado);
}