
#ifndef Y86_LEXER_H
#define Y86_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "token.h"

#define COLON 58
#define SEMICOLON 59
#define UNDERSCORE 95
#define DOT 46
#define SPACE 32
#define PERCNT 37
#define NEWLINE 10
#define COMMA 44
#define OPEN_BRACKT 40
#define CLOSED_BRACKT 41
#define QUOTE 34

#define ISALPHA(x) ((x >= 65 && x <= 90) || (x >= 97 && x <= 121))  
#define ISDIGIT(x) ((x >= 48 && x <= 57 ))

int read_identifier(const char** fptr, node* tail );
int read_number(const char **fptr, node *tail);
int read_string(const char **fptr, node *tail);
int read_punctuation(const char **fptr, node *tail, TokenType type);
void lexer(const char* fptr, node* tokens);

#endif
