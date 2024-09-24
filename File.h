#ifndef FILE_H
#define FILE_H

#include "ListaDesc.h"
#include "ListaDup.h"

/*
   fileLoad()
      1. Checar se o arquivo existe
      2. Checar se o arquivo está vazio
      3. Iterar o arquivo até o EOF, fazendo malloc de cada estrutura
        3.1 Se a linha começar com "|", é uma sequência
        3.2 Salvar filmes que começam com "|" como sequências do filme sem logo acima
      4. fclose()
*/
void fileLoad(FILE *file, Descritor *ld, int *numFilme);

/*
   fileWrite()
      1. Criar o arquivo se não for criado (w)
      2. Escrever o filme na linha onde se encontra na stream, de acordo com as regras no PDF
      3. Pular a linha
      4. Parar quando acabar os nós
*/
void fileWrite(FILE *file, Descritor *ld);

#endif
