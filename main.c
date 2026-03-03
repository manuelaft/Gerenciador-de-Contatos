#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[20];
    char email[70];
}; 

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

void listar(struct Contato contatos[],int total) {
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

int buscarIndice(struct Contato contatos[], int total, char nomeBuscado[]) { // função para achar o indice do contato pelo nome digitado (nomeBuscado)
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, nomeBuscado) == 0) {
            return i; // achou
        }
    }
    return -1; // não achou
}

void busca(struct Contato contatos[], int total) { // função para 2) buscar
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

void editar(struct Contato contatos[],int total) {
    if (total==0) {
        printf("Nenhum contato cadastrado.");
        return;
    }

    char nomeBuscado[50];

    printf("Digite o nome do contato que quer editar: ");
    scanf("%49s",nomeBuscado);

    int index=buscarIndice(contatos,total,nomeBuscado);

    if (index == -1) {
        printf("Contato não encontrado.");
        return;
    }
    editarContato(&contatos[index]); //passando ponteiro
}

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

/* Exemplo de função recursiva simples: contar quantos nomes têm tamanho > N */
int nomes(struct Contato contatos[], int total, int n) {
    if (total == 0) {
        return 0;
    }

    int contaAtual = 0;
    if ((int)strlen(contatos[total - 1].nome) > n) {
        contaAtual = 1;
    }

    return contaAtual + contarNomesMaioresQueN(contatos, total - 1, n);
}

void stats(struct Contato contatos[], int total) {
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