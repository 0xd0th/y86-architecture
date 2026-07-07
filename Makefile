

main:
	gcc src/lexer.c -o build/main && ./build/main '$(arg)'
