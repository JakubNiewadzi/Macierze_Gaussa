a.out: main.o wypisz.o zamiana.o czytaj.o sprosob.o
	$(CC) $^

main.o: wypisz.h zamiana.h czytaj.h sprosob.h
Wypisz.o: wypisz.h
zamiana.o: zamiana.h
czytaj.o: czytaj.h
sprosob.o: sprosob.h