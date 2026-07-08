
#include "../include/lexer.h"

int read_identifier(const char** restrict fptr, node* tail ) {
	Token* curr_token = &tail->token;
	curr_token->type = TOKEN_IDENTIFIER;

	size_t length = 0;
	for ( ; ISALPHA(**fptr) || ISDIGIT(**fptr) || **fptr == PERCNT  ; length++ ) {
		*fptr += 1; 
	}

	curr_token->value.identifier.length = length;
	curr_token->value.identifier.start = (*fptr)-length;

	printf("token:%d\n\tkey: %.*s\n\tlength: %zu\n", curr_token->type, (int)length, curr_token->value.identifier.start, curr_token->value.identifier.length);

	return 0;

}

int read_number(const char** restrict fptr, node* tail) {
	Token* curr_token = &tail->token;
	curr_token->type = TOKEN_NUMBER;
	
	size_t number = 0;
	while(ISDIGIT(**fptr)) {
		number = number*10 + (**fptr-'0');
		*fptr += 1; 
	}

	curr_token->value.i64 = number;
	printf("token:%d\n\tnumber: %ld\n", curr_token->type, curr_token->value.i64);

	return 0;
};


// to-do: terminar read_punctuation
//int read_punctuation( const char** fptr, node* tail, TokenType token_type ) {


//}


// to-do: testar o lexer apos a implementacao do switch
// 				e a troca de posicao do update_tail
void lexer( const char* fptr, node* tokens) {
	
	node* tail = tokens;
	while(*fptr) {
 
		if ( *fptr == SPACE || *fptr == NEWLINE ) {
			fptr++;
			continue;
		}

		if ( *fptr == SEMICOLON ) {
			for ( ; *fptr != NEWLINE && *fptr != '\0'; fptr++);
			continue;
		}

		update_tail(&tail);

		switch(*fptr) {
			case COLON:
				//read_punctuation(&fptr, tail, TOKEN_COLON);
				break;
			case OPEN_BRACKT:
				//read_punctuation(&fptr, tail, TOKEN_OPEN_BRACKT);
				break;
			case CLOSED_BRACKT:
				//read_punctuation(&fptr, tail, TOKEN_CLOSED_BRACKT);
				break;
			case COMMA:
				//read_punctuation(&fptr, tail, TOKEN_COLON);
				break;
			case QUOTE:
				//read_punctuation(&fptr, tail, TOKEN_COLON);
				break;
		} 

		if ( ISALPHA(*fptr) || *fptr == UNDERSCORE || *fptr == DOT || *fptr == PERCNT ) 
			read_identifier(&fptr, tail);
		
		if (ISDIGIT(*fptr)) 
			read_number(&fptr, tail);
	};

}






