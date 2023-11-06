all: teste

teste: pilha-estatica.o main.o
	gcc -o teste pilha-estatica.o main.o

pilha-estatica.o: pilha-estatica.c pilha-estatica.h
	gcc -c pilha-estatica.c -Wall -Werror -Wextra

main.o: main.c pilha-estatica.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o teste