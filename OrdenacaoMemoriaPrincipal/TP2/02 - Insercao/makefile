all: exec
 
exec: main.o geracao.o insercao.o 
	g++ -o exec main.o geracao.o insercao.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 

geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

insercao.o: insercao.c 
	g++ -o insercao.o insercao.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  