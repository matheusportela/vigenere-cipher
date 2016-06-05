/**
 * Vigenère cipher via command-line interface.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vigenere.h"

void parse_args(int argc, char** argv);
void print_help();
void run_vigenere(char* cmd, char* input, char* pass);

int main(int argc, char** argv) {
    parse_args(argc, argv);
    return 0;
}

void parse_args(int argc, char** argv) {
    if (argc == 1) {
        printf("\"cmd\", \"pass\" and \"text\" arguments are missing\n");
        goto error;
    } else if (argc == 2) {
        printf("\"pass\" and \"text\" arguments are missing\n");
        goto error;
    } else if (argc == 3) {
        printf("\"text\" argument is missing\n");
        goto error;
    } else if (argc > 5) {
        printf("Too many arguments\n");
        goto error;
    }

    char* cmd = argv[1];

    if (strlen(cmd) < 1) {
        printf("\"cmd\" must have at least one character\n");
        goto error;
    }

    char* pass = argv[2];

    if (strlen(pass) < 1) {
        printf("\"pass\" must have at least one character\n");
        goto error;
    }

    if ((strcmp(cmd, "encode") != 0) && (strcmp(cmd, "decode") != 0)) {
        printf("\"cmd\" must be either \"encode\" or \"decode\"");
        goto error;
    }

    char* input = argv[3];

    if (strlen(input) < 1) {
        printf("\"input\" must have at least one character\n");
        goto error;
    }

    run_vigenere(cmd, input, pass);
    return;

error:
    print_help();
}

void print_help() {
    printf("Usage: vigenere_cipher cmd pass text\n");
    printf("\nArguments:\n");
    printf("  cmd: Either \"encode\" or \"decode\"\n");
    printf("  pass: Password\n");
    printf("  text: Text to encode/decode\n");
}

void run_vigenere(char* cmd, char* input, char* pass) {
    char* output = malloc(strlen(input) * sizeof(char));

    if (strcmp(cmd, "encode") == 0)
        vigenere_encode(output, input, pass);
    else if (strcmp(cmd, "decode") == 0)
        vigenere_decode(output, input, pass);

    printf("%s\n", output);
    free(output);
}
