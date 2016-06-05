#include "vigenere.h"

void vigenere(char* dst, char* src, char* pass) {
    int i;
    int shift_pos = 0;

    for (i = 0; i < strlen(src); i++)
        dst[i] = encode_char(src[i], pass, &shift_pos);

    /* Ensure trailing null character since `dst` may not have been initialized
     * yet.
     */
    dst[i] = '\0';
}

char encode_char(char c, char* pass, int* shift_pos) {
    return shift_char(c, pass, shift_pos);
}

char shift_char(char c, char* pass, int* shift_pos) {
    char base = 32;
    char interval = 95;
    int pos = c - base;
    int shift = pass[*shift_pos] - base;

    *shift_pos = (*shift_pos + 1) % strlen(pass);

    return(base + ((pos + shift) % interval));
}
