#ifndef CONTATOS_H
#define CONTATOS_H

#include <stdio.h>

struct Contato {
    char nome[50];
    char telefone[20];
    char email[70];
};

void cadastro(struct Contato contatos[], int *total);
void listar(const struct Contato contatos[], int total);
int  buscarIndice(const struct Contato contatos[], int total, const char nomeBuscado[]);
void busca(const struct Contato contatos[], int total);
void editarContato(struct Contato *c);
void editar(struct Contato contatos[], int total);
void excluir(struct Contato contatos[], int *total);
int contarPorInicial(const struct Contato contatos[], int total, char letra);
void stats(const struct Contato contatos[], int total);

#endif