
#include <stdio.h>
#include "../include/lexer.h"

#define FILE_MAX_SIZE 1024 // 1 kibibyte

// entrada:
// 	./yass programa.yas
// argc[0]      argc[1]
int main(int argv, const char** argc ) {
	
	if ( argv < 2 ) {
		fprintf(stderr, "entrada:\n  ./yass programa.yas\n");
		return 1;
	}

	const char* filename = argc[1];
	FILE* fp = fopen(filename, "r" );
	if ( fp == NULL ) {
		fprintf(stderr, "erro ao tentar abrir o arquivo...\n");
		return -1;
	}

	char* fptr = malloc(FILE_MAX_SIZE);
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

	fclose(fp);

	//node* tokens = malloc(sizeof(*tokens));
	//lexer(fptr, tokens);
	
// to-do: implementar o free_tokens em src/tokens.c
	
	free(fptr);
	return 0;
}

