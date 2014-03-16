FLAGS=-Wall -O2
OBJS=main.o hangman.o phraseGen.o intro.o guess.o

hangman: $(OBJS)
	gcc $(OBJS) -o hangman

main.o: main.c
	gcc -c main.c $(FLAGS)

hangman.o: hangman.c hangman.h
	gcc -c hangman.c $(FLAGS)

phraseGen.o: phraseGen.c phraseGen.h
	gcc -c phraseGen.c $(FLAGS)

intro.o: intro.c intro.h
	gcc -c intro.c $(FLAGS)

guess.o: guess.c guess.h
	gcc -c guess.c $(FLAGS)

clean:
	rm $(OBJS)

.PHONY: clean 
