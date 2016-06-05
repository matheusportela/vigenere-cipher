#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vigenere.h"

void test_vigenere_encode(char* input, char* passphrase, char* expected) {
    char result[strlen(expected)];
    vigenere_encode(result, input, passphrase);

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

void test_vigenere_decode(char* input, char* passphrase, char* expected) {
    char result[strlen(expected)];
    vigenere_decode(result, input, passphrase);

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
    test_vigenere_encode("", "", "");
    test_vigenere_encode("", "crypto", "");
    test_vigenere_encode(" ", " ", " ");
    test_vigenere_encode(" ", "!", "!");
    test_vigenere_encode("!", "!", "\"");
    test_vigenere_encode("0", " ", "0");
    test_vigenere_encode("0", "!", "1");
    test_vigenere_encode("01", "!\"", "13");
    test_vigenere_encode("0", "0", "@");
    test_vigenere_encode("0", "A", "Q");
    test_vigenere_encode("0", "a", "q");
    test_vigenere_encode("~", " ", "~");
    test_vigenere_encode("~", "!", " ");
    test_vigenere_encode("~", "\"", "!");
    test_vigenere_encode("a", "_", "A");
    test_vigenere_encode("secret text", "crypto", "WX]cZdcg_ii");
    test_vigenere_decode("WX]cZdcg_ii", "crypto", "secret text");

    printf("Vigenere cipher passed all tests\n");
    return(0);
}
