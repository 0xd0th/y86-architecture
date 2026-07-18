#ifndef Y86_LEXER_H
#define Y86_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "tokens.h"

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
#define TAB 9
#define DOLLAR 36
#define HASH 35
#define DASH 45

static inline uint8_t is_digit( const char c ) {
	return ((c >= '0' && c <= '9' ));
} 
static inline uint8_t is_alpha( const char c ) {
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}	
static inline uint8_t is_hexdec( const char c ) {
	return ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || is_digit(c));
}
static inline uint8_t is_identifier( const char c ) {
	return ( is_alpha(c) || c == PERCNT || c == DOT || c == UNDERSCORE || c == DASH);
}
static inline uint8_t is_white_space( const char c ) {
	return ( c == SPACE || c == NEWLINE || c == TAB );
}

int read_identifier(const char **fptr, node **tail );
int read_number(const char **fptr, node **tail);
int read_string(const char **fptr, node **tail);
int read_punctuation(const char **fptr, node **tail, token_type type);
int lexer(const char *fptr, node **tokens);

#endif
