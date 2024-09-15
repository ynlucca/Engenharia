#include <stdio.h>
#include <stdlib.h>

#include "Filme.h"
#include "ListaDup.h"
#include "ListaDesc.h"

int main() {

   int escolha;

   do {
      printf(
         "Trabalho de ED // Yan & Rafael\n"
         "[1] Inserir um novo filme\n"
         "[2] Alterar os dados de um filme\n"
         "[3] Remover um filme\n"
         "[4] Imprimir a lista de filmes\n"
         "[5] Inserir sequencia de um filme\n"
         "[6] Imprimir sequencia de um filme\n"
         "[7] Remover sequencia de um filme\n"
         "[8] Imprimir filme que antecede um outro\n"
         "[9] Imprimir filme que sucede um outro\n"
         "[10] Sair\n"
      );
        
      scanf("%d", &escolha);

      switch(escolha) {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            break;
         case 7:
            break;
         case 8:
            break;
         case 9:
            break;
         default:
            break;
      }

      system("clear");
   
   } while (escolha >= 1 && escolha <= 10);

   return 0;
}
