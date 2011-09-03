#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdlib.h>
#include <stdio.h>


typedef struct token {
   int category;   /* the integer code returned by yylex */
   char *text;     /* the actual string (lexeme) matched */
   int lineno;     /* the line number on which the token occurs */
   char *filename; /* the source file in which the token occurs */
   int ival;       /* if you had an integer constant, store its value here */
   int *sval;      /* if you had a string constant, malloc space and store */
} token ;        /* the string (less quotes and after escapes) here */

typedef struct tokenlist {
  token *t;
  struct tokenlist *next;
} token_item ;

void addToList(token_item* head, token* new);
void printList(token_item* head);

#endif