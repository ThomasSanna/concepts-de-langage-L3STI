CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/sannaexo2.c src/main.c
OBJ = $(SRC:.c=.o)
EXEC = sannaexo2

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean