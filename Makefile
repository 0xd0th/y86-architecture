
.PHONY: all debug clean

CC := gcc
CFLAGS := -O2 -Wall -Wextra -Werror -fstack-protector-strong -D_FORTIFY_SOURCE=2 -fPIE -pie -Wl,-z,relro,-z,now -z noexecstack
DEBUG := -g

SRC := src
BUILD := build
LEXER := lexer
MAIN := $(BUILD)/main

all: $(MAIN)

debug: CFLAGS = $(DEBUG)
debug: clean $(MAIN)


# ./build/
$(MAIN): $(BUILD)/$(LEXER)/tokens.o $(BUILD)/$(LEXER)/lexer.o $(SRC)/main.c | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD):
	mkdir -p ./$(BUILD)

# ./build/lexer
$(BUILD)/$(LEXER)/lexer.o: $(SRC)/$(LEXER)/lexer.c $(SRC)/$(LEXER)/lexer.h $(BUILD)/$(LEXER)/tokens.o | $(BUILD)/$(LEXER) 
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/$(LEXER)/tokens.o: $(SRC)/$(LEXER)/tokens.c $(SRC)/$(LEXER)/tokens.h | $(BUILD)/$(LEXER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/$(LEXER):
	mkdir -p ./$(BUILD)/$(LEXER)

clean:
	find ./build/ -name *.o | xargs -IOBJ rm OBJ
