
#include "../include/token.h"

int update_tail(node** tail) {

	node* new_token = malloc(sizeof(*new_token));
	if ( new_token == NULL ) {
		fprintf(stderr, "Erro ao alocar memória para new_token, em update_tokens, linha 8\n");
		return -1;
	}

	*new_token = (node){.token = EMPTY_TOKEN, .next = NULL};

	(*tail)->next = new_token;
	*tail = new_token;

	return 0;
}


int free_tokens(node* tokens) {
	
	if (tokens == NULL ){
		fprintf(stderr, "Lista de tokens ja esta vazia...\n");
		return -1;
	}

	//node* temp_node = tokens;

	return 0;
	
}
