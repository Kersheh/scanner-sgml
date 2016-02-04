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

  struct stack_t *scannerStack = newStack(); //track tags
  struct stack_t *errorStack = newStack(); //track failed closing tags

  while((ttype=getToken()) != ENDFILE) {
    printToken(ttype, tokenString);
    /* if open tag, push onto stack */
    if(ttype == 1) push(scannerStack, formatToken(ttype, tokenString));
    /* if close tag, check top of stack for matching open tag */
    if(ttype == 2) {
      /* if close tag does not match top of stack, report error */
      if(strcmp(top(scannerStack), formatToken(ttype, tokenString))) {
        printf("-- Error: closing tag %s with no matching open tag at line %d\n", tokenString, lineno);
      }
      /* if close tag matches top of stack, pop */
      else {
        pop(scannerStack);
      }
    }
  }



  destroyStack(&errorStack);
  destroyStack(&scannerStack);
  return 0;
}