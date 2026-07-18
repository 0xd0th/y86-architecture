
#include "lexer.h"

int read_identifier(const char **fptr, node **tail ) {
	Token curr_token;
	curr_token.type = TOKEN_IDENTIFIER;

	size_t length = 0;
	for ( ; is_identifier(**fptr) || is_digit(**fptr) ; length++ ) {
		*fptr += 1; 
	}

	curr_token.value.identifier.length = length;
	curr_token.value.identifier.start = (*fptr)-length;

	append_tokens(tail, curr_token);

	return 0;

}

int read_number(const char **fptr, node **tail) {
	Token curr_token;
	curr_token.type = TOKEN_NUMBER;

	if ( **fptr == DOLLAR ) 
		(*fptr)++;
	
	size_t integer = 0;
	if ( **fptr == '0' && ( *(*fptr+1) == 'x' || *(*fptr+1) == 'X' ) ) {
		(*fptr) += 2;
		while( is_hexdec(**fptr) ) {
			char hextodec = '0';

			if ( (**fptr) >= 'A' ) {
				hextodec = ('A'-10);
			}

			if ( (**fptr) >= 'a' ) {
					hextodec = ('a'-10);
			}

			integer = integer*16 + (((**fptr)-hextodec));
			(*fptr)++;
		}	
	} else {
		while(is_digit(**fptr)) {
			integer = integer*10 + ((**fptr)-'0');
			(*fptr)++; 
		}
	}

	curr_token.value.i64 = integer;
	append_tokens(tail, curr_token);

	return 0;
};


int read_punctuation( const char **fptr, node **tail, token_type type ) {
	Token curr_token;
	curr_token.type = type;
	curr_token.value.i64 = 0;
	
	append_tokens(tail, curr_token);

	++(*fptr);

	return 0;
}

int lexer( const char *fptr, node **tokens) {

	node* tail = *tokens;	
	while(*fptr) {
 
		if ( (*tokens) == NULL && tail != NULL  ) {
			*tokens = tail;
		}

		for ( ; is_white_space(*fptr) ; fptr++);

		if ( *fptr == HASH ) {
			for ( ; *fptr != NEWLINE && *fptr != '\0'; fptr++);
			continue;
		}

		if ( is_identifier(*fptr) ) { 
			read_identifier(&fptr, &tail);
			continue;
		}
		
		if (is_digit(*fptr) || *fptr == DOLLAR ) {	
			read_number(&fptr, &tail);
			continue;
		}

		switch(*fptr) {
			case COLON:
				read_punctuation(&fptr, &tail, TOKEN_COLON);
				continue;
				break;
			case OPEN_BRACKT:
				read_punctuation(&fptr, &tail, TOKEN_OPEN_BRACKT);
				continue;
				break;
			case CLOSED_BRACKT:
				read_punctuation(&fptr, &tail, TOKEN_CLOSED_BRACKT);
				continue;
				break;
			case COMMA:
				read_punctuation(&fptr, &tail, TOKEN_COLON);
				continue;
				break;
			case QUOTE:
				read_punctuation(&fptr, &tail, TOKEN_COLON);
				continue;
				break;
		} 

	};


	return 0;
}
