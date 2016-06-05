#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vigenere.h"

void test_vigenere(char* input, char* passphrase, char* expected) {
    char result[strlen(expected)];
    vigenere(result, input, passphrase);

    if (!(strcmp(result, expected) == 0)) {
        printf("-------------------\n");
        printf("Failed test\n");
        printf("-------------------\n");
        printf("Input: %s\n", input);
        printf("Passphrase: %s\n", passphrase);
        printf("Expected: %s\n", expected);
        printf("Result: %s\n", result);
        printf("-------------------\n");
        exit(1);
    }
}

int main() {
    /* Empty inputs */
    test_vigenere("", "", "");
    test_vigenere("", "crypto", "");

    test_vigenere(" ", " ", " ");
    test_vigenere(" ", "!", "!");
    test_vigenere("!", "!", "\"");
    test_vigenere("0", " ", "0");
    test_vigenere("0", "!", "1");
    test_vigenere("01", "!\"", "13");
    test_vigenere("0", "0", "@");
    test_vigenere("0", "A", "Q");
    test_vigenere("0", "a", "q");
    test_vigenere("~", " ", "~");
    test_vigenere("~", "!", " ");
    test_vigenere("~", "\"", "!");
    test_vigenere("a", "_", "A");
    test_vigenere("secret text", "crypto", "WX]cZdcg_ii");

    printf("Vigenere cipher passed all tests\n");
    return(0);
}
