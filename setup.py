from distutils.core import setup, Extension

extension = Extension('pyvigenere', sources=['pyvigenere.c', 'vigenere.c'])
setup(
    name='pyvigenere', version='1.0',
    ext_modules=[extension],
    headers=['vigenere.h']
)
