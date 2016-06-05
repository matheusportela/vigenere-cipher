/**
 * Python extension in C for pyvigenere module.
 * Reference: http://dan.iel.fm/posts/python-c-extensions/
 */

#include <Python.h>
#include <stdlib.h>
#include "vigenere.h"

static PyObject* pyvigenere_encode(PyObject* self, PyObject* args) {
    char* input;
    char* pass;

    if (!PyArg_ParseTuple(args, "ss", &input, &pass))
        return NULL;

    char* output = malloc(strlen(input) * sizeof(char));
    vigenere_encode(output, input, pass);
    PyObject* output_obj = Py_BuildValue("s", output);
    free(output);
    return output_obj;
}

static PyObject* pyvigenere_decode(PyObject* self, PyObject* args) {
    char* input;
    char* pass;

    if (!PyArg_ParseTuple(args, "ss", &input, &pass))
        return NULL;

    char* output = malloc(strlen(input) * sizeof(char));
    vigenere_decode(output, input, pass);
    PyObject* output_obj = Py_BuildValue("s", output);
    free(output);
    return output_obj;
}

static PyMethodDef pyvigenere_methods[] = {
    {"encode", pyvigenere_encode, METH_VARARGS, "Encode string with Vigenere \
                                                 cipher algorithm."},
    {"decode", pyvigenere_decode, METH_VARARGS, "Decode string with Vigenere \
                                                 cipher algorithm."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

PyMODINIT_FUNC initpyvigenere() {
    Py_InitModule("pyvigenere", pyvigenere_methods);
}

int main(int argc, char** argv)
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter. Required. */
    Py_Initialize();

    /* Add a static module */
    initpyvigenere();
}
