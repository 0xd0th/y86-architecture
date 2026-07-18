
#include "tokens.h"

int append_tokens(node **tail, Token token) {
	node* new_node = malloc(sizeof(*new_node));
	if (new_node == NULL ) {
		fprintf(stderr, "Erro ao alocar memoria para new_node, em append_token, linha %d\n", __LINE__);
		return -1;
	}

	*new_node = (node){token, NULL};
	
	if ( (*tail) != NULL )
		(*tail)->next = new_node;
	*tail = new_node;
	
	return 0;
}


int free_tokens(node *tokens) {

    if (tokens == NULL ){
		fprintf(stderr, "Lista de tokens ja esta vazia...\n");
		return -1;
	}
	
	for (node *curr_node = tokens ; curr_node != NULL ; curr_node = tokens){
		tokens = tokens->next;
		free(curr_node);
	};

	return 0;
	
}
