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
 * "secret text" -> "crypto" -> "uvagxh vvvi"
 */

#ifndef VIGENERE_H_
#define VIGENERE_H_

#include <string.h>

/* Apply Vigenère cipher algorithm to `src`, a null-terminated string, storing
 * the output in `dst`, another previously allocated null-terminated string. The
 * passphrase `pass` is used to code the input string.
 */
void vigenere(char* dst, char* src, char* pass);

/* Apply Vigenère cipher encoding for a single character `c` using a password
 * string `pass` and the current password character `shift_pos` to use.
 */
char encode_char(char c, char* pass, int* shift_pos);

/* Apply logic for shifting characters using a base character.*/
char shift_char(char c, char* pass, int* shift_pos);

#endif /* VIGENERE_H_ */
