CC = gcc
CFLAGS = -ansi -Wall -g

INC = -I.

.PHONY: all
all: test_vigenere

# Create executable files
test_vigenere: test_vigenere.o vigenere.o
	$(CC) -o $@ $^

# Create object files
.c.o:
	$(CC) $(CFLAGS) $(INC) -c $<

# Clean object files
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f test_vigenere
