#ifndef LISTADESC_H
#define LISTADESC_H

#include "Filme.h"

typedef struct noDesc {
   struct filme *info;
   struct noDesc *prox;
} NoDesc;

typedef struct descritor {
   NoDesc *prim;
   int n;
   NoDesc *ult;
} Descritor;

Descritor criarDescritor();

int estaVaziaDesc(Descritor *ld);

void inserirFilmeDesc(Descritor *ld);

void alterarFilmeDesc(Descritor *ld, int id);

void imprimirFilmesDesc(Descritor* ld);

void removerFilmeDesc(Descritor *ld, int id);

#endif
