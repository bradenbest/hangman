hangman:
	cd src && $(MAKE)
	mv src/hangman ./

clean:
	cd src && $(MAKE) clean

install: hangman
	gzip hangman.1
	sudo cp hangman.1.gz /usr/man/man1/
	gunzip hangman.1.gz
	sudo mv hangman /usr/local/bin/

uninstall:
	sudo rm /usr/man/man1/hangman.1.gz
	sudo rm /usr/local/bin/hangman

.PHONY: hangman clean install uninstall
