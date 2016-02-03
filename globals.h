/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for the SGML               */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern int lineno; /* source line number for listing */

typedef enum
   { /* book-keeping tokens */
     ENDFILE,
     /* reserved keywords */
     IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE,
     /* symbols */
     ASSIGN, EQ, LT, GT, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI,
     /* open token types */
     ID, NUM,
     /* other */
     ERROR
   } TokenType;

#endif
