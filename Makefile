CC=gcc
CFLAGS=-Wall -Wextra  
SRC=src/
BUILD=obj/
BIN=bin/
DEPS=$(BUILD)image.o $(BUILD)pile.o

all: clean main

$(BUILD)%.o : $(SRC)%.c
	$(CC) $(CFLAGS) -o $@ $^ -c

main: $(DEPS) $(BUILD)main.o
	$(CC) $(CFLAGS) -o $(BIN)$@ $^

clean:
	rm -rf obj/*
	rm -rf bin/*