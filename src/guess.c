#include <stdio.h>
#include <string.h>

#include "guess.h"
#include "hangman.h"

char guesses[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static int guessesi = 0;

char incorrect[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static int incorrecti = 0;

char correct[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static int correcti = 0;

int gameover = 0;

static int charInStr(char c, char *str){
  int i; 
  for(i = 0; i < strlen(str); i++){
    if(c == str[i] || c == ' '){
      return 1;
    }
  }
  return 0;
}

static int compare(char *pool, char *phrase){
  int i;
  for(i = 0; i < strlen(phrase); i++){ // look through phrase, and if a char isn't found in correct guesses, game isn't over
    if(!charInStr(phrase[i], correct)){
      return 0;
    }
  }
  return 1;
}

void guess(char *phrase){
  int i;
  int _correct = 0;
  printf("What is your guess? ");
  char inp = getchar();
  if(inp >= 'A' && inp <= 'Z'){
    inp += 0x20;
  }else if(inp >= 'a' && inp <= 'z'){
    inp -= 0;
  }else{
    printf("Enter a letter [a-z] or [A-Z]\n");
    return;
  }

  for(i = 0; i < strlen(guesses); i++){
    if(inp == guesses[i]){
      printf("You've already guessed that!\n");
      return;
    }
  }

  for(i = 0; i < strlen(phrase); i++){
    if(inp == phrase[i]){
      _correct = 1;
    }
  }

  guesses[guessesi++] = inp;

  if(_correct){ // Correct
    correct[correcti++] = inp;
    gameover = compare(correct,phrase);
  }else{ // Incorrect
    incorrect[incorrecti++] = inp;
    addPart();
    if(state == 6){
      gameover = 2;
    }
  }
}
