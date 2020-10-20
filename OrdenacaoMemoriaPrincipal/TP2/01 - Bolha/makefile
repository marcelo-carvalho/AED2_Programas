all: exec
 
exec: main.o geracao.o bolha.o 
	g++ -o exec main.o geracao.o bolha.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 
 
bolha.o: bolha.c 
	g++ -o bolha.o bolha.c -c -W -Wall -pedantic

geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  