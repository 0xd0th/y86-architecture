
CC := gcc
CFLAGS := -O2 -Wall -Wextra -Werror -fstack-protector-strong -D_FORTIFY_SOURCE=2 -fPIE -pie -Wl,-z,relro,-z,now -z noexecstack

SRC := src
BUILD := build
INCLUDE := include

$(BUILD)/main: $(BUILD)/lexer.o $(BUILD)/token.o $(SRC)/main.c
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD)/lexer.o: $(SRC)/lexer.c $(INCLUDE)/lexer.h $(BUILD)/token.o  
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/token.o: $(SRC)/token.c $(INCLUDE)/token.h
	$(CC) $(CFLAGS) -c $< -o $@
