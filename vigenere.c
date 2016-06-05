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
    if (is_lowercase(c))
        return shift_char(c, pass, shift_pos, 'a');
    else if (is_uppercase(c))
        return shift_char(c, pass, shift_pos, 'A');
    return c;
}

int is_lowercase(char c) {
    return(c >= 'a' && c <= 'z');
}

int is_uppercase(char c) {
    return(c >= 'A' && c <= 'Z');
}

char shift_char(char c, char* pass, int* shift_pos, char base) {
    int pos = c - base;
    int shift = pass[*shift_pos] - base;

    *shift_pos = (*shift_pos + 1) % strlen(pass);

    return(base + ((pos + shift) % 26));
}
