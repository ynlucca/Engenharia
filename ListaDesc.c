#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"
#include "ListaDesc.h"

struct filme;

typedef struct noDesc {
   struct filme* info;
   struct noDesc *prox;
} NoDesc;

typedef struct descritor {
   NoDesc *prim;
   int n;
   NoDesc *ult;
} Descritor;

Descritor criarLista(){
   Descritor d;
   d.prim = d.ult = NULL;
   d.n = 0;
   return d;
}

int estaVazia(Descritor *ld){
   return ld->n == 0;
}

void inserirFilme(Descritor *ld){
   NoDesc *cursor = ld->prim;
   NoDesc *ant = NULL;
   struct filme *filmeTemp = leFilme();
   
   //Percorre a Lista Descritora até cursor ser nulo (fim da lista), ou até achar um nó cujo filme seja "alfabeticamente" superior ao filme filmeTemp (filmeTemp->nomeFilme < cursor->filme->nomeFilme)
   while(cursor != NULL && (strcmp(filmeTemp->nomeFilme, cursor->info->nomeFilme) == -1))
   {
      ant = cursor;
      cursor = cursor->prox;  
   }
   
   //Cria um novo nó com o filme filmeTemp
   NoDesc *novo = (NoDesc*) malloc(sizeof(NoDesc));
   novo->info->idFilme = numFilme++;
   strcpy(novo->info->nomeFilme, filmeTemp->nomeFilme);
   novo->info->anoFilme = filmeTemp->anoFilme;
   novo->prox = cursor;
   
   //Caso seja inserido na primeira posição, o ponteiro da lista apontará ao novo nó. Caso contrário, o anterior apontará ao novo nó
   if(ant == NULL) 
      ld->prim = novo;
   else
      ant->prox = novo;
   
}

void imprimirListaFilmes(Descritor* ld){
   printf("\n");
   if(!estaVazia(ld))
   {
      NoDesc *cursor;
    
      //Percorre toda a lista
      for(cursor = ld->prim; cursor != NULL; cursor = cursor->prox)
      {
         imprimeFilme(cursor->info);
      }
   }
   else
      printf("\nERR: Lista vazia!\n");
}

void removerFilme(Descritor *ld, struct filme *f){
   if(!estaVazia(ld))
   {
      NoDesc *cursor = ld->prim;
      NoDesc *ant = NULL;

     //Loop de busca para o nó desejado
      while((cursor->info->idFilme != f->idFilme) && (cursor != NULL))
      {
         ant = cursor;
         cursor = cursor->prox;    
      }
 
     //Caso o cursor chegue ao final da lista sem encontrar o nó desejado
      if(cursor == NULL)
      {
         printf("\nELemento nn encontrado\n");
      }
      else
      {
         //Caso o nó desejado seja o primeiro da lista
         if(ant == NULL)
         {
            ld->prim = cursor->prox;
            
            //Caso o nó desejado seja o único da lista
            if(ld->prim == NULL)
               ld->ult = NULL;
         }
         else
         {
            ant->prox = cursor->prox;
            
            //Caso o nó desejado seja o último da lista
            if(cursor->prox == NULL)
               ld->ult = ant;
         }
 
      free(cursor);
      ld->n--;
   }
 
   }
   else
      printf("\nERR: Lista vazia!\n");
}