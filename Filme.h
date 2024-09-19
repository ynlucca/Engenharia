#ifndef FILME_H
#define FILME_H

extern int numFilme;

typedef struct filme Filme; 

Filme* leFilme(); 

int retornaAno(Filme* f);

void imprimeFilme(Filme* f);

void alterarNome(Filme* f);

void alterarAno(Filme* f); 

#endif
