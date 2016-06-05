CC = gcc
CFLAGS = -ansi -Wall -g

INC = -I.

.PHONY: all
all: vigenere_cipher test_vigenere

# Create executable files
vigenere_cipher: vigenere_cipher.o vigenere.o
	$(CC) -o $@ $^

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
	-rm -f vigenere_cipher
	-rm -f test_vigenere
