# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXECS = exoA1 exoA2 exoA3 exoA4 exoA5 exoA61 exoA7

# Règle par défaut
all: $(EXECS)

# Règles pour chaque exécutable
exoA1: exoA1.c
	$(CC) $(CFLAGS) -o $@ $<

exoA2: exoA2.c
	$(CC) $(CFLAGS) -o $@ $<

exoA3: exoA3.c
	$(CC) $(CFLAGS) -o $@ $<

exoA4: exoA4.c
	$(CC) $(CFLAGS) -o $@ $<

exoA5: exoA5.c
	$(CC) $(CFLAGS) -o $@ $<

exoA61: exoA61.c
	$(CC) $(CFLAGS) -o $@ $<

exoA7: exoA7.c
	$(CC) $(CFLAGS) -o $@ $<

# Nettoyage des fichiers générés
clean:
	del $(EXECS)