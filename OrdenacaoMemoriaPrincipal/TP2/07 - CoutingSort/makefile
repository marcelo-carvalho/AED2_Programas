all: exec
 
exec: main.o geracao.o countingsort.o 
	g++ -o exec main.o geracao.o countingsort.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 
 
countingsort.o: countingsort.c 
	g++ -o countingsort.o countingsort.c -c -W -Wall -pedantic

geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  