/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"

int idDoFilme = 0; //só pra fins de teste, quando a gente for mexer com a variável externa conserta

typedef struct filme Filme;

typedef struct tnode{
   Filme* filme;
   struct tnode* prox;
} No;

typedef struct tdescritor{
   No* prim;
   int n;
   No* ult;
} Descritor;

Descritor criarLista(){
   Descritor d;
   d.prim = d.ult = NULL;
   d.n = 0;
   return d;
}

int estaVazia(Descritor *ld){
   return (ld->n == 0);
}

void inserirFilme(No** ld){
   No *cursor = *ld, *ant = NULL;
   Filme *f = leFilme();
   
   //Percorre a Lista Descritora até cursor ser nulo (fim da lista), ou até achar um nó cujo filme seja "alfabeticamente" superior ao filme f (f->nomeFilme < cursor->filme->nomeFilme)
   while(cursor != NULL && (strcmp((f->nomeFilme), cursor->(filme->nomeFilme)) == -1))
   {
      ant = cursor;
      cursor = cursor->prox;  
   }
   
   //Cria um novo nó com o filme f
   No* novo = (No*) malloc(sizeof(No));
   novo->(filme->id) = idDoFilme++;
   novo->filme->nomeFilme = f->nomeFilme;
   novo->filme->anoFilme = f->anoFilme;
   novo->prox = cursor;
   
   //Caso seja inserido na primeira posição, o ponteiro da lista apontará ao novo nó. Caso contrário, o anterior apontará ao novo nó
   if(ant == NULL) 
      *ld = novo;
   else
      ant->prox = novo;
   
}

void imprimeListaFilmes(Descritor* ld){
   printf("\n");
   if(!estaVazia(ld))
   {
      No* cursor;
    
      //Percorre toda a lista
      for(cursor = ld->prim; cursor != NULL; cursor = cursor->prox)
      {
         imprimeFilme(cursor->filme);
      }
   }
   else
      printf("\nlista vazia\n");
}

void removerFilme(Descritor *ld, Filme* f){
   if(!estaVazia(ld))
   {
      No* cursor = ld->prim, *ant = NULL;

	  //Loop de busca para o nó desejado
      while((cursor->filme->idFilme != f->idFilme)&&(cursor != NULL))
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
      printf("\nesta vazia\n");

}
*/
