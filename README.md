# Hangman game by Braden Best

A port of the original from Python to C

It's designed for Linux, but uses the C standard library

Which means you should be able to compile for windows or mac.

Compiling for Linux
-
It's just one command:
    $ make
That's it. It's compiled. To run:
    $ ./hangman

Compiling for Windows
-
To compile for windows, you'll need the MinGW C compiler. If you want to try it with a different compiler, be my guest, but this guide assumes you've installed MinGW
    > gcc main.c intro.c phraseGen.c hangman.c guess.c -o hangman.exe
I'm not sure how to run it in windows. Probably something like
    > hangman.exe
while in the directory where hangman.exe is

Compiling for Mac
-
Should be the same, more or less, as Linux.

In any case, try to have gcc, make, and build-essentials installed. If you can get make, then a simple
    $ make
should work like a charm

Otherwise, you'll have to compile it manually, in a similar manner to the windows instructions:
    $ gcc main.c intro.c phraseGen.c hangman.c guess.c -o hangman
