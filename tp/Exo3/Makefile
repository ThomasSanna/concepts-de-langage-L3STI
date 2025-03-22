CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/sannaexo3.c
OBJ = $(SRC:.c=.o)
EXEC = sannaexo3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean