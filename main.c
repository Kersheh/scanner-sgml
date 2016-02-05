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

  int relevant = 0; //track if current tag section is relevant to print -- 0 is relevant, > 0 is irrelevant

  while((ttype=getToken()) != ENDFILE) {
    /* if open tag, push onto stack */
    if(ttype == 1) {
      push(scannerStack, formatToken(ttype, tokenString));
      if(relevant > 0) relevant++; //increment relevant flag for any tag inside irrelevant tag
      else if(!compareToken(top(scannerStack))) relevant++; //increment relevant flag on irrelevant tag
    }
    /* if close tag, check top of stack for matching open tag */
    if(ttype == 2) {
      /* if close tag does not match top of stack, report error */
      if(strcmp(top(scannerStack), formatToken(ttype, tokenString))) {
        printf("-- Error: closing tag %s with no matching open tag at line %d\n", formatToken(ttype, tokenString), lineno);
      }
      /* if close tag matches top of stack, pop */
      else {
        pop(scannerStack);
        /* decrement relevant tag on pop if greater than 0 */
        if(relevant > 0) {
          relevant--;
          continue;
        }
      }
    }
    /* print tokens if relevant */
    if(relevant == 0) printToken(ttype, tokenString);
  }

  while(top(scannerStack)) {
    printf("-- Error: opening tag %s with no closing tag left over in stack\n", top(scannerStack));
    pop(scannerStack);
  }

  destroyStack(&errorStack);
  destroyStack(&scannerStack);
  return 0;
}