#ifndef FILME_H
#define FILME_H

#include "ListaDup.h"

//Variável utilizada na atualização global dos ids
extern int numFilme; 

//Estrutura do Filme
typedef struct filme { 
   int idFilme;
   int anoFilme;
   char nomeFilme[100];
   struct noDup *seqFilme;
} Filme;

//Função que lê um filme
Filme* leFilme();

//Função que retorna o ano em que o filme foi publicado
int retornaAno(Filme* f);

//Função que exibe um filme no terminal
void imprimeFilme(Filme* f);

//Função para atualizar o nome de um filme
void alterarNome(Filme* f);

//Função para atualizar o ano de um filme
void alterarAno(Filme* f);

#endif
