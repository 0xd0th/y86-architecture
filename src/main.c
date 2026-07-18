
#include <stdio.h>
#include "./lexer/lexer.h"

#define FILE_MAX_SIZE 1024 // 1kib

// entrada:
// 	./yass programa.yas
// argc[0]      argc[1]
int main(int argv, const char** argc ) {
	
	if ( argv < 2 ) {
		fprintf(stderr, "entrada:\n  ./yass programa.yas\n");
		return 1;
	}

	const char *filename = argc[1];
	FILE *fp = fopen(filename, "r" );
	if ( fp == NULL ) {
		fprintf(stderr, "erro ao tentar abrir o arquivo...\n");
		return -1;
	}

	char *fptr = malloc(FILE_MAX_SIZE);
	if ( fptr == NULL ) {
		fprintf(stderr, "erro ao alocar memoria para comportar o conteudo do arquivo\n");
		fclose(fp);
		return -1;
	}

	size_t fsize = fread(fptr, sizeof(char), FILE_MAX_SIZE, fp);
	printf("bytes lidos: %ld\n", fsize);
	if ( ferror(fp) ) {
		fprintf(stderr, "erro ao tentar le o conteudo do arquivo\n");
		free(fptr);
		fclose(fp);
		return -1;
	} 

	node *tokens = NULL;
	lexer(fptr, &tokens);
	
	if (tokens != NULL)
		free_tokens(tokens);

	free(fptr);
	return 0;

}

