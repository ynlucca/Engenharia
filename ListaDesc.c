#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaDesc.h"
#include "Filme.h"
#include "ListaDup.h"

Descritor criarDescritor(){
   Descritor d;
   d.prim = d.ult = NULL;
   d.n = 0;
   return d;
}

int estaVaziaDesc(Descritor *ld){
   return ld->n == 0;
}

void inserirFilmeDesc(Descritor *ld){
   NoDesc *cursor = ld->prim;
   NoDesc *ant = NULL;
   Filme *filmeTemp = leFilme();

   //Percorre a Lista Descritora até cursor ser nulo (fim da lista), ou até achar um nó cujo filme seja "alfabeticamente" superior ao filme filmeTemp (filmeTemp->nomeFilme < cursor->filme->nomeFilme)
   while(cursor != NULL && (strcmp(filmeTemp->nomeFilme, cursor->info->nomeFilme) > 0))
   {
      ant = cursor;
      cursor = cursor->prox;  
   }
   
   //Cria um novo nó com o filme filmeTemp
   NoDesc *novo = (NoDesc*) malloc(sizeof(NoDesc));
   novo->info = filmeTemp;
   novo->prox = cursor;
   
   //Caso seja inserido na primeira posição, o ponteiro da lista apontará ao novo nó. Caso contrário, o anterior apontará ao novo nó
   if(ant == NULL) 
      ld->prim = novo;
   else
      ant->prox = novo;

   //Aumenta o numero de elementos do Descritor
   ld->n++;
}

void alterarFilmeDesc(Descritor *ld, int id) {
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!\n");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDesc *cursor_1 = ld->prim;
   NoDup *cursor_2 = NULL;

   for (cursor_1; cursor_1 != NULL && cursor_1->info->idFilme != id; cursor_1 = cursor_1->prox) {
      if (cursor_1->info->seqFilme != NULL) {
         cursor_2 = cursor_1->info->seqFilme;
         for (cursor_2; cursor_2 != NULL && cursor_2->info->idFilme != id; cursor_2 = cursor_2->prox) {
            if (cursor_2->info->idFilme == id) {
               alterarNome(cursor_2->info);
               alterarAno(cursor_2->info);
               return;
            }
         }
      }
   }

   if (cursor_1 == NULL) {
      printf("\nERR: Filme nao encontrado!\n");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   if (cursor_1->info->idFilme == id) {
      alterarNome(cursor_1->info);
      alterarAno(cursor_1->info);
      return;
   }
}

void imprimirFilmesDesc(Descritor* ld){
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!\n");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDesc *cursor_1 = ld->prim;
   NoDup *cursor_2 = NULL;

   printf("\n");
   //Percorre toda a lista
   for(cursor_1; cursor_1 != NULL; cursor_1 = cursor_1->prox)
   {
      imprimeFilme(cursor_1->info);
      printf("\n");
      if (cursor_1->info->seqFilme != NULL) {
         cursor_2 = cursor_1->info->seqFilme;
         for (cursor_2; cursor_2 != NULL; cursor_2 = cursor_2->prox) {
            printf("\t");
            imprimeFilme(cursor_2->info);
            printf("\n");
         }
      }
      printf("\n");
   }

   setbuf(stdin, NULL);
   printf("Pressione algo para continuar...");

   getchar();
}

void removerFilmeDesc(Descritor *ld, int id){
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!\n");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDesc *cursor = ld->prim;
   NoDesc *ant = NULL;

   //Loop de busca para o nó desejado
   for (cursor; cursor != NULL && cursor->info->idFilme != id; cursor = cursor->prox) {
      ant = cursor;
   }

   //Caso o cursor chegue ao final da lista sem encontrar o nó desejado
   if(cursor == NULL)
   {
      printf("\nERR: Elemento nao encontrado!\n");
      printf("\nPressione algo para continuar...");
      setbuf(stdin, NULL);
      getchar();
      return;
   }
   else
   {
      //Liberando os filmes da sequência
      if(cursor->info->seqFilme != NULL){
         NoDup* franq = cursor->info->seqFilme;
         NoDup* aux = NULL;
         while(franq != NULL){
            aux = franq->prox;
            free(franq);
            franq = aux;
         }   
      }
      
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
