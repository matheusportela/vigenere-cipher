/**
 * Vigenère cipher algorithm implementation for didactic purposes.
 * Author: Matheus Vieira Portela
 * GitHub: https://github.com/matheusportela/
 *
 * Vigenère cipher is one of the earliest cipher algorithms in history. Once
 * named "le chiffre indéchiffrable", this polyalphabetic substitution cipher
 * has pretty simple steps whereas it is quite difficult to break (at least it
 * was until the 20th century as computers haven't been invented yet).
 *
 * First, select a passphrase such as "crypto". Each letter is mapped to the
 * integer number representing their position in the alphabet starting at 0. In
 * this example, "crypto" corresponds to the numbers [2, 17, 24, 15, 19, 14].
 *
 * Now, encode an input text such as "secret text" using the passphrase shifts,
 * one letter at a time. If the passphrase is smaller than the input text,
 * simply keep repeating the passphrase ad infinitum.
 *
 * Example:
 * "secret text" -> "crypto" -> "WX]cZdcg_ii"
 */

#ifndef VIGENERE_H_
#define VIGENERE_H_

#include <string.h>

#define BASE 32
#define INTERVAL 95

/* Encode a null-terminated string `src` with the password `pass` and store the
 * store the result in `dst`.
 */
void vigenere_encode(char* dst, char* src, char* pass);

/* Decode a null-terminated string `src` with the password `pass` and store the
 * store the result in `dst`.
 */
void vigenere_decode(char* dst, char* src, char* pass);

/* Apply Vigenère cipher algorithm to `src`, a null-terminated string, storing
 * the output in `dst`, another previously allocated null-terminated string. The
 * passphrase `pass` is used to code the input string.
 */
void vigenere(char* dst, char* src, char* pass, int encode);

/* Encode a single character with Vigenère cipher using one character of the
 * password.
 */
char encode_char(char c, char pass);

/* Decode a Vigenère cipher encoded character using one character of the
 * password.
 */
char decode_char(char c, char pass);

/* Shift a character using one character of the password. The flag `encode`
 * indicates whether the character should be shifted to the positive side
 * (encode) or the negative side (decode).
 */
char shift_char(char c, char pass, int encode);

#endif /* VIGENERE_H_ */
