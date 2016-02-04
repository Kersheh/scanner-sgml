/*******************************************************************************/
/* File: stack.h                                                               */
/* Stack functions in C from:                                                  */
/* http://stackoverflow.com/questions/1919975/creating-a-stack-of-strings-in-c */
/*******************************************************************************/

#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <string.h>

/* Type for individual stack entry */
struct stack_entry {
  char *data;
  struct stack_entry *next;
};

/* Type for stack instance */
struct stack_t {
  struct stack_entry *head;
  size_t stackSize;
};

struct stack_t *newStack(void);
char *copyString(char *str);
void push(struct stack_t *theStack, char *value);
char *top(struct stack_t *theStack);
void pop(struct stack_t *theStack);
void clear(struct stack_t *theStack);
void destroyStack(struct stack_t **theStack);

#endif