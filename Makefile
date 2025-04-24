CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/filesystem.c
OBJ = $(SRC:.c=.o)
EXEC = filesystem

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean