CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/sannaexo1.c src/sannalisteint.c
OBJ = $(SRC:.c=.o)
EXEC = sannaexo1

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC) saveliste.bin

.PHONY: all clean