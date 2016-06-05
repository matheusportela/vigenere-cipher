#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "vigenere.h"

#define DEBUG 0

void test_vigenere(char* input, char* passphrase, char* expected) {
    char result[strlen(expected)];
    vigenere(result, input, passphrase);

    if (DEBUG) {
        printf("-------------------\n");
        printf("Input: %s\n", input);
        printf("Passphrase: %s\n", passphrase);
        printf("Expected: %s\n", expected);
        printf("Result: %s\n", result);
        printf("-------------------\n");
    }

    assert(strcmp(result, expected) == 0);
}

int main() {
    /* Empty inputs */
    test_vigenere("", "", "");
    test_vigenere("", "crypto", "");

    /* Lowercase letters */
    test_vigenere("secret text", "crypto", "uvagxh vvvi");

    /* Uppercase letters */
    test_vigenere("SECRET TEXT", "CRYPTO", "UVAGXH VVVI");

    printf("Vigenere cipher passed all tests\n");
    return(0);
}
