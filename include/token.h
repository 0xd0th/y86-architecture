
#ifndef Y86_TOKEN_H
#define Y86_TOKEN_H

#define EMPTY_TOKEN (Token){.type = TOKEN_EMPTY, .value.i64 = 0}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


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

typedef struct _node { 
	Token token; 
	struct _node* next; 
} node;

int update_tail(node** tail);
int free_tokens(node* tokens);

#endif
