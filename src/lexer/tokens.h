
#ifndef Y86_TOKEN_H
#define Y86_TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
	TOKEN_COMMA,
	TOKEN_COLON,
	TOKEN_OPEN_BRACKT,
	TOKEN_CLOSED_BRACKT,
	TOKEN_NEWLINE,
	TOKEN_EOF
} token_type;

typedef struct {
	token_type type;

	union {
		struct { 
				const char *start;
				size_t length;
		} identifier;

		struct {
			const char *start;
			size_t length;
		} string;
		
		uint64_t i64;
		double db;
	} value;

} Token;

typedef struct _node { 
	Token token; 
	struct _node *next; 
} node;

int append_tokens(node **tail, Token token);
int free_tokens(node *tokens);

#endif
