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
    push(scannerStack, tokenString);
  }

  destroyStack(&scannerStack);
  return 0;
}