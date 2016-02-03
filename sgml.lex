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
number      [-+]?{digit}*\.?{digit}+
letter      [a-zA-Z]
word        ({letter}|{digit})+
punctuation [/\[.,\/#!$%\^&\*;:{}=\-_`~()\]]
newline     \n
whitespace  [ \t]+

%%

"<"{word}">"                {return OPEN;} //missing support for attributes
"</"{word}">"               {return CLOSE;}
{word}\'{word}(\'{word})?   {return APOSTROPHIZED;}
{word}\-{word}(\-{word})*   {return HYPHENATED;}
{number}                    {return NUMBER;}
{word}                      {return WORD;}
{punctuation}               {return PUNCTUATION;}
{newline}                   {lineno++;}
{whitespace}                {/* skip whitespace */}
.                           {return ERROR;}

%%

TokenType getToken(void) { 
  static int firstTime = TRUE;
  TokenType currentToken;
  if(firstTime) {
    firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString, yytext, MAXTOKENLEN);
  return currentToken;
}