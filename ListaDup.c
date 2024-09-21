#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"
#include "ListaDesc.h"
#include "ListaDup.h"

int estaVaziaDup(NoDup *nd) {
   return nd == NULL;
}

void inserirFilmeDup(struct descritor *ld, int id) {
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDesc *cursor_1 = ld->prim;
   NoDup *cursor_2 = NULL;

   for (cursor_1; cursor_1 != NULL && cursor_1->info->idFilme != id; cursor_1 = cursor_1->prox);

   if (cursor_1->info->idFilme != id || cursor_1 == NULL) {
      printf("\nERR: Filme para iniciar sequencia nao encontrado!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDup *novo = (NoDup*) malloc(sizeof(NoDup));
   novo->info = leFilme();

   if (cursor_1->info->seqFilme == NULL) {
      cursor_1->info->seqFilme = novo;
      novo->ant = NULL;
      novo->prox = NULL;
   } else {
      cursor_2 = cursor_1->info->seqFilme;
      for (cursor_2; cursor_2->prox != NULL; cursor_2 = cursor_2->prox); 
      cursor_2->prox = novo;
      novo->prox = NULL;
      novo->ant = cursor_2;
   }
}

void imprimirFilmesDup(struct descritor *ld, int id) {
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDesc *cursor_1 = ld->prim;

   for (cursor_1; cursor_1 != NULL && cursor_1->info->idFilme != id; cursor_1 = cursor_1->prox);

   if (cursor_1->info->idFilme != id || cursor_1 == NULL) {
      printf("\nERR: Filme para iniciar sequencia nao encontrado!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDup *cursor_2 = cursor_1->info->seqFilme;

   imprimeFilme(cursor_1->info);
   printf("\n");

   for (cursor_2; cursor_2 != NULL; cursor_2 = cursor_2->prox) {
      printf("\t");
      imprimeFilme(cursor_2->info);
      printf("\n");
   }

   printf("\n");

   setbuf(stdin, NULL);
   printf("\nPressione algo para continuar...");
   getchar();
}

void removerFilmeDup(struct descritor *ld, int id) {
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDesc *cursor_1 = ld->prim;
   
   for (cursor_1; cursor_1 != NULL && cursor_1->info->idFilme != id; cursor_1 = cursor_1->prox);

   if (cursor_1->info->idFilme != id || cursor_1 == NULL) {
      printf("\nERR: Filme para iniciar sequencia nao encontrado!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   NoDup *cursor_2 = cursor_1->info->seqFilme;

   printf("\n");
   imprimeFilme(cursor_1->info);
   printf("\n");

   for (cursor_2; cursor_2 != NULL; cursor_2 = cursor_2->prox) {
      printf("\t");
      imprimeFilme(cursor_2->info);
      printf("\n");
   }

   int idCont;
   printf("\nDigite o ID da continuacao para que seja deletada: ");
   scanf("%d", &idCont);

   cursor_2 = cursor_1->info->seqFilme;
   NoDup *aux = NULL;
   for (cursor_2; cursor_2->prox != NULL && cursor_2->info->idFilme != idCont; cursor_2 = cursor_2->prox) {
      aux = cursor_2;
   }

   if (cursor_2->info->idFilme != idCont || cursor_2 == NULL) {
      printf("\nERR: Nao ha continuacao com esse ID!");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      getchar();
      return;
   }

   if (aux == NULL) {
      cursor_1->info->seqFilme = cursor_2->prox;
      if (cursor_1->info->seqFilme != NULL) {
         cursor_2->prox->ant = NULL;
      }
   } else {
      aux->prox = cursor_2->prox;
      if (cursor_2->prox != NULL) {
         cursor_2->prox->ant = aux;
      }
   }

   free(cursor_2);
}

void imprimirAntDup(struct descritor *ld, int id) {
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!");
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
      if (cursor_1->info->idFilme == id) {
         printf("\nO filme < %s > nao possui anterior...", cursor_1->info->nomeFilme);
         setbuf(stdin, NULL);
         printf("\nPressione algo para continuar...");
         getchar();
         return;
      }
      if (cursor_1->info->seqFilme != NULL) {
         cursor_2 = cursor_1->info->seqFilme;
         for (cursor_2; cursor_2 != NULL; cursor_2 = cursor_2->prox) {
            if (cursor_2->info->idFilme == id) {
               if (cursor_2->ant == NULL) {
                  printf("Anterior:\n");
                  imprimeFilme(cursor_1->info);
               } else {
                  printf("Anterior:\n");
                  imprimeFilme(cursor_2->ant->info);
               }
            }
         }
      }
   }

   setbuf(stdin, NULL);
   printf("\nPressione algo para continuar...");
   getchar();
}

void imprimirSucDup(struct descritor *ld, int id) {
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia!");
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
      if (cursor_1->info->idFilme == id) {
         printf("Sucessor:\n");
         imprimeFilme(cursor_1->info->seqFilme->info);
      }
      if (cursor_1->info->seqFilme != NULL) {
         cursor_2 = cursor_1->info->seqFilme;
         for (cursor_2; cursor_2 != NULL; cursor_2 = cursor_2->prox) {
            if (cursor_2->info->idFilme == id) {
               if (cursor_2->prox == NULL) {
                  printf("\nO filme < %s > nao possui sucessor...", cursor_2->info->nomeFilme);
                  setbuf(stdin, NULL);
                  printf("\nPressione algo para continuar...");
                  getchar();
                  return;
               } else {
                  printf("Sucessor:\n");
                  imprimeFilme(cursor_2->prox->info);
               }
            }
         }
      }
   }

   setbuf(stdin, NULL);
   printf("\nPressione algo para continuar...");
   getchar();
}
