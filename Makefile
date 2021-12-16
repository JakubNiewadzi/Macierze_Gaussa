a.out: main.o wypisz.o zamiana.o czytaj.o
	$(CC) $^

main.o: wypisz.h zamiana.h czytaj.h
Wypisz.o: wypisz.h
zamiana.o: zamiana.h
czytaj.o: czytaj.h