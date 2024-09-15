#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"

typedef struct filme Filme; 

typedef struct listaDup {
	Filme* info;
	struct listaDup* prox;
	struct listaDup* ant;
} ListaDup;

ListaDup* criarListaVazia() {
	ListaDup* l = NULL;
	return l;
}
