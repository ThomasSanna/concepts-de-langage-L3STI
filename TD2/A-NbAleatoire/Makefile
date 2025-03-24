CC = gcc
CFLAGS = -Wall -Wextra -g
SRC1 = src/util_rand.c src/dice.c src/main.c
OBJ1 = $(SRC1:.c=.o)
EXEC1 = main

SRC2 = src/util_rand.c src/statistique.c
OBJ2 = $(SRC2:.c=.o)
EXEC2 = statistique

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJ1)
	$(CC) $(OBJ1) -o $@

$(EXEC2): $(OBJ2)
	$(CC) $(OBJ2) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) $(EXEC1) $(EXEC2)

.PHONY: all clean