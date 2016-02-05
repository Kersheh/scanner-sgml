/****************************************************/
/* File: util.h                                     */
/* Utility functions for SGML.                      */
/****************************************************/

#ifndef _UTIL_H_
#define _UTIL_H_

/* compare token to relevant tokens */
int compareToken(char* str);
/* strip tags of brackets and convert uppercase */
char* formatToken(int token, const char* str);

/* prints a token and its value to the listing file */
void printToken(int, const char*);

#endif