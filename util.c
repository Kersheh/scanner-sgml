/****************************************************/
/* File: util.c                                     */
/* Utility function implementation for SGML.        */
/****************************************************/

#include <string.h>
#include "globals.h"
#include "util.h"

void stringToUppercase(char* str) {
  int i;
  for(i = 0; i < strlen(str); i++) {
    str[i] = toupper(str[i]);
  }
}

char* formatToken(int token, const char* str) {
  int i;
  char *trim = malloc(sizeof(str));
  if(token == 1) {
    for(i = 0; i < strlen(str) - 2; i++) {
      trim[i] = str[i + 1];
    }
    trim[strlen(str) - 2] = '\0';
  }
  else if(token == 2) {
    for(i = 0; i < strlen(str) - 3; i++) {
      trim[i] = str[i + 2];
    }
    trim[strlen(str) - 3] = '\0';
  }
  else strcpy(trim, str);
  stringToUppercase(trim);
  return trim;
}

/* prints a token and its lexeme to the listing file */
void printToken(int token, const char* tokenString) { 
  switch (token) {
    case ENDFILE: 
      break;
    case OPEN:
      fprintf(listing, "OPEN-%s\n", formatToken(token, tokenString));
      break;
    case CLOSE:
      fprintf(listing, "CLOSE-%s\n", formatToken(token, tokenString));
      break;
    case WORD:
      fprintf(listing, "WORD(%s)\n", formatToken(token, tokenString));
      break;
    case NUMBER:
      fprintf(listing, "NUMBER(%s)\n", formatToken(token, tokenString));
      break;
    case APOSTROPHIZED:
      fprintf(listing, "APOSTROPHIZED(%s)\n", formatToken(token, tokenString));
      break;
    case HYPHENATED:
      fprintf(listing, "HYPHENATED(%s)\n", formatToken(token, tokenString));
      break;
    case PUNCTUATION:
      fprintf(listing, "PUNCTUATION(%s)\n", formatToken(token, tokenString));
      break;
    case ERROR:
      fprintf(listing, "ERROR(%s)\n", formatToken(token, tokenString));
      break;
    default: /* should never happen */
      fprintf(listing, "Unknown(%s)\n", formatToken(token, tokenString));
  }
}