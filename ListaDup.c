#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"

typedef struct filme Filme; 

typedef struct noDup {
	Filme* info;
	struct listaDup* prox;
	struct listaDup* ant;
} NoDup;

NoDup* criarListaVazia() {
	NoDup* l = NULL;
	return l;
}
