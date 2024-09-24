#ifndef LISTADUP_H
#define LISTADUP_H

#include "Filme.h"
#include "ListaDesc.h"

struct descritor;

//Estrutura do nó duplamente encadeado
typedef struct noDup {
	struct filme *info;
	struct noDup *prox;
	struct noDup *ant;
} NoDup;

//Função que verifica se a lista de sequências está vazia
int estaVaziaDup(NoDup *nd);

//Função que insere uma sequência ao filme principal
void inserirFilmeDup(struct descritor *ld, int id);

//Função que insere uma sequência ao filme principal para arquivo
void inserirFilmeDupFile(struct descritor *ld, int id, struct filme *tempFilme);

//Função que imprime as sequências de um filme
void imprimirFilmesDup(struct descritor *ld, int id);

//Função que permite remover uma sequência da lista
void removerFilmeDup(struct descritor *ld, int id);

//Função que exibe o antecessor de um filme
void imprimirAntDup(struct descritor *ld, int id);

//Função que exibe o sucessor de um filme
void imprimirSucDup(struct descritor *ld, int id);

#endif
