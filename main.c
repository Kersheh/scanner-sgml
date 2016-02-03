/****************************************************/
/* File: main.c                                     */
/* Main program for the SGML scanner                */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"

/* allocate global variables */
int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

int main( int argc, char * argv[] )
{ 
  TokenType ttype;
  source = stdin;
  listing = stdout; 
  while( (ttype=getToken())!= ENDFILE )
    printToken( ttype, tokenString );
  return 0;
}

