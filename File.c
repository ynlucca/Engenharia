#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "File.h"
#include "ListaDup.h"
#include "ListaDesc.h"
#include "Filme.h"

#define NAME "data.txt"

/*
   fileLoad()
      1. Checar se o arquivo existe
      2. Checar se o arquivo está vazio
      3. Iterar o arquivo até o EOF, fazendo malloc de cada estrutura
        3.1 Se a linha começar com "|", é uma sequência
        3.2 Salvar filmes que começam com "|" como sequências do filme sem logo acima
      4. fclose()
*/
void fileLoad(FILE *file, Descritor *ld, int *numFilme) {
   int numFilmeTemp = 0;
   char buffer[256];

   file = fopen(NAME, "r");
   
   //Checando se o arquivo existe
   if (file == NULL) {
      printf("\nArquivo não existe ou não foi criado.\n");
      return;
   }

   //Checando se o arquivo está vazio
   fseek(file, 0, SEEK_END); //Essa linha coloca o ponteiro da "stream" no final com um offset de 0
   if (ftell(file) == 0) {
      printf("\nArquivo vazio.\n");
      fclose(file);
      return;
   }

   //Essa linha volta o ponteiro pro começo
   rewind(file);

   Filme *aux = NULL;
   while(fgets(buffer, sizeof(buffer), file) != NULL) {
      //Não Sequência
      if(buffer[0] != '|') {
         Filme *ftemp = (Filme*) malloc(sizeof(Filme));
         
         int token_ct = 0;
         char *token; //substring temporária
         token = strtok(buffer, "\t");
         while (token != NULL) {
            if (token_ct == 0) {
               ftemp->idFilme = atoi(token);
            } else if (token_ct == 1) {
               strcpy(ftemp->nomeFilme, token);
            } else if (token_ct == 2) {
               ftemp->anoFilme = atoi(token);
            }
            token = strtok(NULL, "\t"); //Próximo token
            token_ct++;
         }
         ftemp->seqFilme = NULL;
         aux = ftemp;

         numFilmeTemp++;
         inserirFilmeDescFile(ld, ftemp);
      } else {
         Filme *ftemp = (Filme*) malloc(sizeof(Filme));

         int token_ct = 0;
         char *token; //substring temporária
         token = strtok(buffer, "|\n");
         while (token != NULL) {
            if (token_ct == 0) {
               ftemp->idFilme = atoi(token);
            } else if (token_ct == 1) {
               ftemp->anoFilme = atoi(token);
            } else if (token_ct == 2) {
               strcpy(ftemp->nomeFilme, token);
            }
            token = strtok(NULL, "|\n"); //Próximo token
            token_ct++;
         }

         numFilmeTemp++;
         inserirFilmeDupFile(ld, aux->idFilme, ftemp);
      }
   }

   *numFilme = numFilmeTemp + 1;
   fclose(file);
}

/*
   fileWrite()
      1. Criar o arquivo se não for criado (w)
      2. Escrever o filme na linha onde se encontra na stream, de acordo com as regras no PDF
      3. Pular a linha
      4. Parar quando acabar os nós
*/
void fileWrite(FILE *file, Descritor *ld) {
   file = fopen(NAME, "w");
   
   if(estaVaziaDesc(ld)) { //Checar se a lista esta vazia!
      printf("\nERR: Lista vazia! Salvamento não concluido!\n");
      setbuf(stdin, NULL);
      printf("\nPressione algo para continuar...");
      fclose(file);
      getchar();
      return;
   }

   NoDesc *cursor_1 = ld->prim;
   NoDup *cursor_2 = NULL;

   //Percorre toda a lista
   for(cursor_1; cursor_1 != NULL; cursor_1 = cursor_1->prox)
   {
      //Filme "Pai"
      char pai[256];
      char formato_pai[256] = "%d\t%s\t%d\n";
      sprintf(
         pai,
         formato_pai,
         cursor_1->info->idFilme,
         cursor_1->info->nomeFilme,
         cursor_1->info->anoFilme
      );
      fputs(pai, file);

      if (cursor_1->info->seqFilme != NULL) {
         cursor_2 = cursor_1->info->seqFilme;
         for (cursor_2; cursor_2 != NULL; cursor_2 = cursor_2->prox) {
            //Filme "Filho"
            char filho[256];
            char formato_filho[256] = "|%d|%d|%s\n";
            sprintf(
               filho,
               formato_filho,
               cursor_2->info->idFilme,
               cursor_2->info->anoFilme,
               cursor_2->info->nomeFilme
            );
            fputs(filho, file);
         }
      }
   }
}