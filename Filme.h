#ifndef FILME_H
#define FILME_H

#include "ListaDup.h"

extern int numFilme;

typedef struct filme {
   int idFilme;
   int anoFilme;
   char nomeFilme[100];
   struct noDup *seqFilme;
} Filme;

Filme* leFilme();

int retornaAno(Filme* f);

void imprimeFilme(Filme* f);

void alterarNome(Filme* f);

void alterarAno(Filme* f);

#endif
