#ifndef LISTADUP_H
#define LISTADUP_H

#include "Filme.h"
#include "ListaDesc.h"

struct descritor;

typedef struct noDup {
	struct filme *info;
	struct noDup *prox;
	struct noDup *ant;
} NoDup;

int estaVaziaDup(NoDup *nd);

void inserirFilmeDup(struct descritor *ld, int id);

void imprimirFilmesDup(struct descritor *ld, int id);

void removerFilmeDup(struct descritor *ld, int id);

void imprimirAntDup(struct descritor *ld, int id);

void imprimirSucDup(struct descritor *ld, int id);

#endif
