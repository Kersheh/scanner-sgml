/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the SGML                                     */
/****************************************************/

#include "globals.h"
#include "util.h"

/* prints a token and its lexeme to the listing file
 */
void printToken( int token, const char* tokenString )
{ switch (token) {
    case ENDFILE: 
      break;
    case IF:
      fprintf(listing, "IF\n" );
      break;
    case THEN:
      fprintf(listing, "THEN\n" );
      break;
    case ELSE:
      fprintf(listing, "ELSE\n" );
      break;
    case END:
      fprintf(listing, "END\n" );
      break;
    case REPEAT:
      fprintf(listing, "REPEAT\n" );
      break;
    case UNTIL:
      fprintf(listing, "UNTIL\n" );
      break;
    case READ:
      fprintf(listing, "READ\n" );
      break;
    case WRITE:
      fprintf(listing, "WRITE\n" );
      break;
    case ASSIGN: 
      fprintf(listing, "ASSIGN\n"); 
      break;
    case LT: 
      fprintf(listing, "LT\n"); 
      break;
    case GT: 
      fprintf(listing, "GT\n"); 
      break;
    case EQ: 
      fprintf(listing, "EQ\n"); 
      break;
    case LPAREN: 
      fprintf(listing, "LPAREN\n"); 
      break;
    case RPAREN: 
      fprintf(listing, "RPAREN\n"); 
      break;
    case SEMI: 
      fprintf(listing, "SEMI\n"); 
      break;
    case PLUS: 
      fprintf(listing, "PLUS\n"); 
      break;
    case MINUS: 
      fprintf(listing, "MINUS\n"); 
      break;
    case TIMES: 
      fprintf(listing, "TIMES\n"); 
      break;
    case OVER: 
      fprintf(listing, "OVER\n"); 
      break;
    case NUM:
      fprintf(listing, "NUM(%s)\n", tokenString);
      break;
    case ID:
      fprintf(listing, "ID(%s)\n", tokenString);
      break;
    case ERROR:
      fprintf(listing, "ERROR(%s)\n", tokenString);
      break;
    default: /* should never happen */
      fprintf(listing, "Unknown(%s)\n", tokenString);
  }
}
