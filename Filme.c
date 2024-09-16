#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaDup.h"
#include "Filme.h"

//Conta quantos filmes tem para incremento automático do id.
int numFilme = 1;

struct noDup;
typedef struct filme Filme;

Filme* leFilme() {
	//Aloco espaço para um filme, fazendo um ponteiro de Filme, f, receber o endereço.
	Filme* f = (Filme*) malloc(sizeof(Filme));

	//O id do filme recebe numFilme, e depois numFilme se altera.
	f->idFilme = numFilme;
	numFilme++;

	//O ponteiro seqFilme recebe NULL.
	f->seqFilme = NULL;

	//Recebendo o nome do filme.
	printf("\nNome do Filme (Lim: 100 Caracteres): ");
	setbuf(stdin, NULL); //Limpando o Buffer por precaução ;)
	scanf("%[^\n]", f->nomeFilme);

	//Recebendo o ano do filme.
	printf("\nAno de lancamento do filme: ");
	setbuf(stdin, NULL);
	scanf("%d", &f->anoFilme);

	return f;
}

int retornaAno(Filme* f) {
	//Retorno o ano do filme.
	return f->anoFilme; 
}

void imprimeFilme(Filme* f) {
	//Abaixo, printo as informações requisitadas do filme.
	printf("\nID: %d -- Nome: %s -- Ano: %d\n", f->idFilme, f->nomeFilme, f->anoFilme);
}

void alterarNome(Filme* f) {
	//Abaixo, altero as informações do novo filme.
	printf("\nDigite o novo nome do filme: ");
	setbuf(stdin, NULL);
	scanf("%[^\n]", f->nomeFilme);
}

void alterarAno(Filme* f) {
	//Abaixo, altero as informações do ano de lançamento do filme.
	printf("\nDigite o novo ano de lancamento do filme: ");
	setbuf(stdin, NULL);
	scanf("%d", &f->anoFilme);
}
