


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

inline void update_tokens(node** tail) {
	node* new_token = malloc(sizeof(*new_token));
	*new_token = (node){.token = {0}, .next = NULL};
	(*tail)->next = new_token;
	*tail = new_token;
}

void lexer( const char* fptr ) {
	
	node* tokens = malloc(sizeof(*tokens));
	*tokens = (node){.token = {0}, .next = NULL};
	node* tail = tokens;
	while(*fptr) {
 
		if ( *fptr == SPACE || *fptr == NEWLINE ) {
			fptr++;
			continue;
		}

		if ( *fptr == COLON ) {
			//read_punctuation(&fptr, tail, TOKEN_COLON);
			update_tokens(&tail);	
		}

		if ( *fptr == OPEN_BRACKT ) {
			//read_punctuation(&fptr, tail, TOKEN_OPEN_BRACKT);
			update_tokens(&tail);
		}

		if ( *fptr == CLOSED_BRACKT ) {
			//read_punctuation(&fptr, tail, TOKEN_CLOSED_BRACKT);
			update_tokens(&tail);
		}


		if ( *fptr == COMMA ) {
			//read_punctuation(&fptr, tail, TOKEN_COMMA);
			update_tokens(&tail);
		}

		if ( *fptr == QUOTE ) {
			//read_string(*fptr, tail);
			update_tokens(&tail);
		}

		if ( *fptr == SEMICOLON )
			for ( ; *fptr != NEWLINE && *fptr != '\0'; fptr++);
		
		if ( ISALPHA(*fptr) || *fptr == UNDERSCORE || *fptr == DOT || *fptr == PERCNT ) {
			read_identifier(&fptr, tail);
			update_tokens(&tail);
		}
		if (ISDIGIT(*fptr)) {
			read_number(&fptr, tail);
			update_tokens(&tail);
		}
	
	};
}



int main(void) {
				
	char* f = malloc(128);
	fread(f,1, 128, stdin);
	printf("%s\n", f);
	lexer(f);

	return 0;
}



