#include <stdio.h>
#include <stdlib.h>

#include "Filme.h"
#include "ListaDup.h"
#include "ListaDesc.h"

int main() {

   int escolha, val;
   Descritor desc = criarDescritor();

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
         "> "
      );
        
      scanf("%d", &escolha);

      switch(escolha) {
         case 1:
            inserirFilmeDesc(&desc);
            break;
         case 2:
            printf("\nDigite o ID unico do filme para altera-lo: ");
            scanf("%d", &val);
            alterarFilmeDesc(&desc, val);
            break;
         case 3:
            printf("\nDigite o ID unico do filme para remove-lo: ");
            scanf("%d", &val);
            removerFilmeDesc(&desc, val);
            break;
         case 4:
            imprimirFilmesDesc(&desc);
            break;
         case 5:
            printf("\nDigite o ID unico do filme para adicionar sequencia: ");
            scanf("%d", &val);
            inserirFilmeDup(&desc, val);
            break;
         case 6:
            printf("\nDigite o ID unico do filme para imprimir a sequencia: ");
            scanf("%d", &val);
            imprimirFilmesDup(&desc, val);
            break;
         case 7:
            printf("\nDigite o ID unico do filme para apagar um de sua sequencia: ");
            scanf("%d", &val);
            removerFilmeDup(&desc, val);
            break;
         case 8:
            printf("\nDigite o ID unico do filme para imprimir seu anterior: ");
            scanf("%d", &val);
            imprimirAntDup(&desc, val);
            break;
         case 9:
            printf("\nDigite o ID unico do filme para imprimir seu sucessor: ");
            scanf("%d", &val);
            imprimirSucDup(&desc, val);
            break;
         default:
            break;
      }

      system("clear");

   } while (escolha >= 1 && escolha < 10);

   return 0;
}
