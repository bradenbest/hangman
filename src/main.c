#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "phraseGen.h"
#include "hangman.h"
#include "intro.h"
#include "guess.h"

#ifdef UNIX
#  define CLEAR "\033[2J"
#else
#  define NLX5 "\n\n\n\n\n"
#  define CLEAR NLX5 NLX5 NLX5 NLX5 NLX5 NLX5 //30 newlines should do the trick
#endif

void stat(char *phrase){
  int i,j, cont = 0;
  printf(CLEAR);
  fflush(stdout);
  printf(SEPARATOR);
  draw();
  printf("Incorrect guesses: ");
  for(i = 0; i < strlen(incorrect); i++){
    printf("%c ", incorrect[i]);
  }
  printf("\n");
  // Fill out blanks
  for(i = 0; i < strlen(phrase); i++){
    for(j = 0; j < strlen(correct); j++){
      if(phrase[i] == correct[j]){
        printf("%c", correct[j]);
        cont = 1;
        break;
      }
    }
    if(cont){
      cont = 0;
      continue;
    }
    if(phrase[i] == 32){
      printf(" ");
    }else{
      printf("_");
    }
  }
  printf("\n");
}

int main(int argc, char **argv){
  srand(time(0));
  intro();
  char phrase[1000];
  if(argc > 1){
    setPhrase(phrase,argv[1]);
  }else{
    generatePhrase(phrase);
  }
  while(1){
    stat(phrase);
    guess(phrase);
    if(gameover)    break;
  }
  if(gameover == 2){
    printf("Game Over!\nThe phrase was \"%s\"\n", phrase);
  }else if(gameover == 1){
    printf("You Win!!!\nCongraturation! Your story is happy end!\nGame Over!\n");
  }
  return 0;
}
