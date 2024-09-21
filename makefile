all: comp execu clean
comp: main.o ListaDup.o ListaDesc.o Filme.o
	gcc main.o ListaDup.o ListaDesc.o Filme.o -o prog
Filme.o: Filme.c
	gcc -c Filme.c
ListaDup.o: ListaDup.c
	gcc -c ListaDup.c
ListaDesc.o: ListaDesc.c
	gcc -c ListaDesc.c
main.o: main.c
	gcc -c main.c
execu:
	./prog
clean:
	rm main.o ListaDup.o ListaDesc.o Filme.o prog
