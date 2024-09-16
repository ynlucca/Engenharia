#ifndef LISTADESC_H
#define LISTADESC_H

#include "Filme.h"

typedef struct filme Filme;

typedef struct noDesc NoDesc;

typedef struct descritor Descritor;

Descritor criarLista();

int estaVazia(Descritor *ld);

void inserirFilme(Descritor *ld);

void imprimirListaFilmes(Descritor* ld);

void removerFilme(Descritor *ld, Filme *f);

#endif