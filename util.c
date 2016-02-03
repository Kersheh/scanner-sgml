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
    case OPEN:
      fprintf(listing, "OPEN-%s\n", tokenString);
      break;
    case CLOSE:
      fprintf(listing, "CLOSE-%s\n", tokenString);
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
