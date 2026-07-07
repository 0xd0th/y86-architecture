
#ifndef Y86_LEXER_H
#define Y86_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

typedef enum {
	TOKEN_EMPTY,
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
	TOKEN_STRING,
	TOKEN_CHAR,
	TOKEN_COMMA,
	TOKEN_COLON,
	TOKEN_OPEN_BRACKT,
	TOKEN_CLOSED_BRACKT,
	TOKEN_NEWLINE,
	TOKEN_EOF
} TokenType;

typedef struct {
	TokenType type;

	union {
		struct { 
				const char* start;
				size_t length;
		} identifier;

		struct {
			const char* start;
			size_t length;
		} string;
		
		uint64_t i64;
		double db;
	} value;

} Token;

typedef struct _node { Token token; struct _node* next; } node;

int read_identifier(const char** fptr, node* tail );
int read_number(const char **fptr, node *tail);
int read_string(const char **fptr, node *tail);
int read_punctuation(const char **fptr, node *tail, TokenType type);
inline void update_tokens(node** tail);
void lexer( const char* fptr );

#endif
