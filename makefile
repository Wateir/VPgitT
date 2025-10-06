CC = gcc
SRC = main.c
TARGET = prog

MAX_LENGTH ?= 256

CFLAGS = -Wall -Wextra -D MAX_LENGTH=$(MAX_LENGTH)

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
