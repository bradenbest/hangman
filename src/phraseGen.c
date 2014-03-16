#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phraseGen.h"

const char phraselist[25][25] = {
  {'t','e','r','m','i','n','a','l',' ','t','e','r','m','i','n','a','t','i','o','n',0}, 
  {'r','e','f','l','e','x',' ','p','a','y','b','a','c','k', 0},
  {'d','u','k','e',' ','o','f',' ','j','e','o','p','a','r','d','y', 0},
  {'d','o','u','b','l','e',' ','a','s','s','a','s','s','i','n','a','t','i','o','n', 0},
  {'q','u','a','d','r','u','p','l','e',' ','r','i','s','k', 0},
  {'w','a','r',' ','f','o','r',' ','i','m','p','a','c','t', 0},
  {'t','r','i','p','l','e',' ','p','u','n','i','s','h','m','e','n','t', 0},
  {'m','a','x','i','m','u','m',' ','e','x','t','r','e','m','i','s','m', 0},
  {'s','o','l','d','i','e','r',' ','o','f',' ','h','u','m','i','l','i','a','t','i','o','n', 0},
  {'v','e','n','d','e','t','t','a',' ','o','f',' ','v','i','c','t','o','r','y', 0},
  {'b','a','t','t','l','e',' ','o','f',' ','e','x','e','c','u','t','i','o','n', 0},
  {'e','x','t','r','e','m','e',' ','r','e','t','r','i','b','u','t','i','o','n', 0},
  {'i','n','f','i','n','i','t','e',' ','d','o','m','i','n','a','t','i','o','n', 0},
  {'f','a','t','a','l',' ','o','v','e','r','k','i','l','l', 0},
  {'m','a','s','t','e','r',' ','o','f',' ','r','e','t','r','e','a','t', 0},
  {'f','i','s','t',' ','o','f',' ','j','u','s','t','i','c','e', 0},
  {'i','n','s','t','a','n','t',' ','e','x','t','e','r','m','i','n','a','t','i','o','n', 0},
  {'i','n','f','e','r','n','o',' ','o','f',' ','h','o','n','o','r', 0},
  {'s','u','d','d','e','n',' ','a','c','t','i','o','n', 0},
  {'m','a','x','i','m','u','m',' ','g','l','o','r','y', 0},
  {'i','n','f','e','r','n','o',' ','o','f',' ','s','u','r','r','e','n','d','e','r', 0},
  {'f','a','t','a','l',' ','b','l','o','o','d', 0},
  {'m','a','s','t','e','r',' ','o','f',' ','v','e','n','g','e','a','n','c','e', 0},
  {'f','i','s','t',' ','o','f',' ','t','r','o','u','b','l','e', 0},
  {'e','x','t','r','e','m','e',' ','c','o','n','q','u','e','s', 0},
};

void generatePhrase(char *phrase){
  int i;
  for(i = 0; i < strlen(phrase); i++){
    phrase[i] = 0;
  }
  strcat(phrase,phraselist[rand() % 25]);
}

void setPhrase(char *phrase, char *src){
  int i;
  for(i = 0; i < strlen(src); i++){
    if(src[i] >= 'A' && src[i] <= 'Z'){
      src[i] += 0x20;
    }else if(!((src[i] >= 'a' && src[i] <= 'z') || (src[i] == ' '))){
      printf("Error: Use only letters [a-z] and [A-Z]\n");
      exit(1);
    }
  }
  strcpy(phrase,src);
}
