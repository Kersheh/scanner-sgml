/****************************************************/
/* File: util.c                                     */
/* Utility function implementation for SGML.        */
/****************************************************/

#include <string.h>
#include "globals.h"
#include "util.h"
#define REL_TOKENS 7

/* compare token to relevant tokens */
int compareToken(char* str) {
  char *relevantTokens[] = {
    "TEXT", "DATE", "DOC", "DOCNO", "HEADLINE", "LENGTH", "P"
  };
  int i;
  for(i = 0; i < REL_TOKENS; i++) if(!strcmp(str, relevantTokens[i])) return 1;
  return 0;
}

/* convert string tp uppercase */
void stringToUppercase(char* str) {
  int i;
  for(i = 0; i < strlen(str); i++) {
    str[i] = toupper(str[i]);
  }
}

/* format token stripping brackets */
char* formatToken(int token, const char* str) {
  int i;
  char *trim = (char*)malloc(sizeof(str));
  /* if open tag, strip string and tokenize */
  if(token == 1) {
    for(i = 0; i < strlen(str) - 2; i++) {
      trim[i] = str[i + 1];
      /* if tag contains attribute, end tokenization */
      if(trim[i] == ' ') {
        trim[i] = '\0';
        break;
      }
    }
    trim[strlen(str) - 2] = '\0';
  }
  /* if close tag, strip string and tokenize */
  if(token == 2) {
    for(i = 0; i < strlen(str) - 3; i++) {
      trim[i] = str[i + 2];
    }
    trim[strlen(str) - 3] = '\0';
  }
  /* normalize tag tokens to upper case */
  stringToUppercase(trim);
  return trim;
}

/* prints a token and its lexeme to the listing file */
void printToken(int token, const char* tokenString) { 
  switch (token) {
    case ENDFILE: 
      break;
    case OPEN:
      fprintf(listing, "OPEN-%s\n", formatToken(token, tokenString)); //format open-tag tokens before print
      break;
    case CLOSE:
      fprintf(listing, "CLOSE-%s\n", formatToken(token, tokenString)); //format close-tag tokens before print
      break;
    case WORD:
      fprintf(listing, "WORD(%s)\n", tokenString);
      break;
    case NUMBER:
      fprintf(listing, "NUMBER(%s)\n", tokenString);
      break;
    case APOSTROPHIZED:
      fprintf(listing, "APOSTROPHIZED(%s)\n", tokenString);
      break;
    case HYPHENATED:
      fprintf(listing, "HYPHENATED(%s)\n", tokenString);
      break;
    case PUNCTUATION:
      fprintf(listing, "PUNCTUATION(%s)\n", tokenString);
      break;
    case ERROR:
      fprintf(listing, "ERROR(%s)\n", tokenString);
      break;
    default: /* should never happen */
      fprintf(listing, "Unknown(%s)\n", tokenString);
  }
}