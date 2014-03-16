#include <stdio.h>

#include "hangman.h"

const char states[7][60] = {
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  },
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ','O',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  },
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ','O',' ',' ',' ','|','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  },
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ','O',' ',' ',' ','|','\n',
    '/','|',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  },
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ','O',' ',' ',' ','|','\n',
    '/','|','\\',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  },
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ','O',' ',' ',' ','|','\n',
    '/','|','\\',' ',' ','|','\n',
    '/',' ',' ',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  },
  {
    '\n','\n',
    ' ','+','-','-','-','+','\n',
    ' ','|',' ',' ',' ','|','\n',
    ' ','O',' ',' ',' ','|','\n',
    '/','|','\\',' ',' ','|','\n',
    '/',' ','\\',' ',' ','|','\n',
    ' ',' ',' ',' ',' ','|','\n',
    '=','=','=','=','=','=','=','\n',0
  }
};

int state = 0;

void draw(){
  printf("%s\n", states[state]);
}
void addPart(){
  state++;
}