#include "vigenere.h"

void vigenere_encode(char* dst, char* src, char* pass) {
    vigenere(dst, src, pass, 1);
}

void vigenere_decode(char* dst, char* src, char* pass) {
    vigenere(dst, src, pass, 0);
}

void vigenere(char* dst, char* src, char* pass, int encode) {
    int i;
    int j;
    int pass_len = strlen(pass);

    for (i = 0, j = 0; i < strlen(src); i++, j++) {
        if (encode)
            dst[i] = encode_char(src[i], pass[j % pass_len]);
        else
            dst[i] = decode_char(src[i], pass[j % pass_len]);
    }

    /* Ensure trailing null character since `dst` may not have been initialized
     * yet.
     */
    dst[i] = '\0';
}

char encode_char(char c, char pass) {
    return shift_char(c, pass, 1);
}

char decode_char(char c, char pass) {
    return shift_char(c, pass, 0);
}

char shift_char(char c, char pass, int encode) {
    int pos = c - BASE;
    int shift = pass - BASE;
    int delta;

    if (encode) {
        delta = pos + shift;
    } else {
        delta = pos - shift;

        if (delta < 0)
            delta += INTERVAL;
    }

    return(BASE + (delta % INTERVAL));
}
