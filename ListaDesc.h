#ifndef LISTADESC_H
#define LISTADESC_H

#include "Filme.h"

//Estrutura do nó da lista descritora
typedef struct noDesc {
   struct filme *info;
   struct noDesc *prox;
} NoDesc;

//Estrutura da lista descritora
typedef struct descritor {
   NoDesc *prim;
   int n;
   NoDesc *ult;
} Descritor;

//Função que retorna um descritor vazio
Descritor criarDescritor();

//Função que verifica se um descritor está vazio
int estaVaziaDesc(Descritor *ld);

//Função de inserção na lista descritora
void inserirFilmeDesc(Descritor *ld);

//Função que permite a alteração de um filme da lista
void alterarFilmeDesc(Descritor *ld, int id);

//Função que permite exibir todos os filmes salvos na lista
void imprimirFilmesDesc(Descritor* ld);

//Função para remover um filme da lista
void removerFilmeDesc(Descritor *ld, int id);

#endif
