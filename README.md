# vigenere-cipher
Didactic implementation of Vigenère Cipher in C. A C extension for Python is also provided.

## What is the Vigenère cipher?

Quoting the [Wikipedia's article on Vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher):

> The Vigenère cipher is a method of encrypting alphabetic text by using a series of different Caesar ciphers based on the letters of a keyword. It is a simple form of polyalphabetic substitution.

> The Vigenère cipher has been reinvented many times. The method was originally described by Giovan Battista Bellaso in his 1553 book La cifra del. Sig. Giovan Battista Bellaso; however, the scheme was later misattributed to Blaise de Vigenère in the 19th century, and is now widely known as the "Vigenère cipher".

> Though the cipher is easy to understand and implement, for three centuries it resisted all attempts to break it; this earned it the description le chiffre indéchiffrable (French for 'the indecipherable cipher'). Many people have tried to implement encryption schemes that are essentially Vigenère ciphers. Friedrich Kasiski was the first to publish a general method of deciphering a Vigenère cipher.

## Why implementing it?

This is my second algorithm implemented throughout my studies in cryptography. The first one was the [Caesar cipher](https://github.com/matheusportela/caesar-cipher), also implemented in C and with a Python extension.

## Command-Line Interface
If you simply want to use my program to encode something, say to strengthen your password, you only need to interact with the command-line interface program.

First, build the software using `make` command:
```bash
$ make
```

Now, simply execute it giving a shift integer and a text to encode:
```bash
$ ./vigenere_cipher encode crypto "secret text"
WX]cZdcg_ii
$ ./vigenere_cipher decode crypto "WX]cZdcg_ii"
secret text
$ ./vigenere_cipher encode crypto "the answer to the ultimate question of life the universe and everything"
X[_pV^Wj_ctdSrnYZoY_nZbQXXybjUWgc\`coSYy]^VIrnYZoYacgZbWXyRcTcXpVgiX[c_\
$ ./vigenere_cipher decode crypto "X[_pV^Wj_ctdSrnYZoY_nZbQXXybjUWgc\`coSYy]^VIrnYZoYacgZbWXyRcTcXpVgiX[c_\\"
the answer to the ultimate question of life the universe and everything
$ ./vigenere_cipher encode 42 "the answer to the ultimate question of life the universe and everything"
)zy2u!(*y%4\'$2)zy2*~){\"s)w4$*w(\'}\"#2$x4~}xy2)zy2*!})y%(w4s#v4w+w\',)z}!{
```

## C
Since you have the source code in your hands, you may want to use it in your own programs. In order to achieve that, you only have to import the header file and call the `vigenere_encode` or `vigenere_decode` methods.

Three arguments are required:
* `char* output`: Allocated `char` array to store the output of the algorithm.
* `char* input`: Allocated null-terminated `char` array containing text to be encoded.
* `char* pass`: Allocated null-terminated `char` to encode the text with.

Let's create an example program. Copy and paste this piece of code to `my_vigenere.c`.
```c
#include <stdio.h>
#include "vigenere.h"

int main() {
  char input[] = "secret text";
  char output[12];
  char pass[] = "crypto"

  vigenere_encode(output, input, pass);
  printf("%s\n", output);
  return 0;
}
```

Now you can compile the program and see it working.
```bash
$ gcc -c my_vigenere.c vigenere.c
$ gcc -o my_vigenere my_vigenere.o vigenere.o
$ ./my_vigenere
WX]cZdcg_ii
```

## Python
A Python module was also created so you can use the implemented Vigenère cipher inside Python scripts. Simply install it using the provided `setup.py` script as follows:
```bash
$ python setup.py install
```

From now on, `pyvigenere` is available for your Python modules:
```python
>>> import pyvigenere
>>> pyvigenere.encode('secret text', 'crypto')
'WX]cZdcg_ii'
>>> pyvigenere.decode('WX]cZdcg_ii', 'crypto')
'secret text'
```

Since it has been programmed in C and exported as an extension, `pyvigenere` benefits from ultrafast execution. Here follows the benchmark executed in IPython:
```python
>>> %timeit pyvigenere.encode('secret text', 'crypto')
The slowest run took 7.24 times longer than the fastest. This could mean that an intermediate result is being cached
1000000 loops, best of 3: 395 ns per loop
```
