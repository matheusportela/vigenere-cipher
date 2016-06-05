/**
 * Vigenère cipher via command-line interface.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vigenere.h"

void parse_args(int argc, char** argv);
void print_help();
void run_vigenere(char* input, char* pass);

int main(int argc, char** argv) {
    parse_args(argc, argv);
    return 0;
}

void parse_args(int argc, char** argv) {
    if (argc == 1) {
        printf("\"pass\" and \"text\" arguments are missing\n");
        goto error;
    } else if (argc == 2) {
        printf("\"text\" argument is missing\n");
        goto error;
    } else if (argc > 3) {
        printf("Too many arguments\n");
        goto error;
    }

    char* pass = argv[1];

    if (strlen(pass) < 1) {
        printf("\"pass\" must have at least one character\n");
        goto error;
    }

    char* input = argv[2];

    if (strlen(input) < 1) {
        printf("\"input\" must have at least one character\n");
        goto error;
    }

    run_vigenere(input, pass);
    return;

error:
    print_help();
}

void print_help() {
    printf("Usage: vigenere_cipher pass text\n");
}

void run_vigenere(char* input, char* pass) {
    char* output = malloc(strlen(input) * sizeof(char));
    vigenere_encode(output, input, pass);
    printf("%s\n", output);
    free(output);
}
