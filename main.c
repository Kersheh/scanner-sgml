/****************************************************/
/* File: main.c                                     */
/* Main program for the SGML scanner.               */
/****************************************************/

#include <stdio.h>
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "stack.h"

/* allocate global variables */
int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

int main(int argc, char * argv[]) { 
  TokenType ttype;
  source = stdin;
  listing = stdout;

  struct stack_t *scannerStack = newStack();

  while((ttype=getToken()) != ENDFILE) {
    printToken(ttype, tokenString);
    if(ttype == 1) push(scannerStack, formatToken(ttype, tokenString));
    if(ttype == 2) {
      printf("Popped: %s\n", top(scannerStack));
      pop(scannerStack);
    }
  }

  destroyStack(&scannerStack);
  return 0;
}