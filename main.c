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

  int relevant = 0; //track if current tag section is relevant to print -- 0 is relevant, > 0 is irrelevant, < 0 is no tags

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
      if(top(scannerStack) == NULL || strcmp(top(scannerStack), formatToken(ttype, tokenString))) {
        if(relevant == 0) printf("-- Error: CLOSE-TAG </%s> with no matching open tag at top of stack at line %d\n", formatToken(ttype, tokenString), lineno);
        continue;
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
    /* print tokens if relevant and tag is on stack */
    if(relevant == 0 && top(scannerStack) != NULL) printToken(ttype, tokenString);
  }

  /* print off remaining tags in stack as errors */
  while(top(scannerStack)) {
    printf("-- Error: OPEN-TAG <%s> with no closing tag left over in stack\n", top(scannerStack));
    pop(scannerStack);
  }

  destroyStack(&scannerStack);
  return 0;
}