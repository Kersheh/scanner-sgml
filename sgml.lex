/****************************************************/
/* File: sgml.lex                                   */
/* Flex specification for SGML                      */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN + 1];
%}

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+

%%

"<"({letter}|{digit})+">"   {return OPEN;} //missing support for attributes
"</"({letter}|{digit})+">"  {return CLOSE;}
'?\b[0-9A-Za-z\']+\b'?      {return APOSTROPHIZED;}
({letter}|{digit})+         {return WORD;}
[-+]?[0-9]*\.?[0-9]+        {return NUMBER;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
"{"[^\}]*"}"    {/* skip comments */}
.               {return ERROR;}

%%

TokenType getToken(void) { 
  static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime) {
    firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString, yytext, MAXTOKENLEN);
  return currentToken;
}