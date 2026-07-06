#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <stdio.h>
#include "my_lib.h"
#include <string>
#include <iostream>

int return_int(int var_int) {

    const char *py_script = 
        "def return_int(x):\n"
        "    return x\n";

    std::string command = "return_int(" + std::to_string(var_int) + ")";

    Py_Initialize();

    PyObject *pdict = PyDict_New();
    
    PyRun_String(py_script, Py_file_input, pdict, pdict);
    const char * statement = command.c_str();
    PyObject* value = PyRun_String(statement, Py_eval_input, pdict, pdict);
    int result = PyLong_AsLong(value);

    Py_Finalize();
    
    return result;
}

std::string return_str(std::string var_str) {

    const char* setup =
        "def return_str(name):\n"
        "    return name\n";

    std::string command = "return_str('" + var_str + "')";

    Py_Initialize();

    PyObject *pdict = PyDict_New();
    Py_ssize_t size = 0;

    PyRun_String(setup, Py_file_input, pdict, pdict);
    const char * statement = command.c_str();
    PyObject* ret = PyObject_Str(PyRun_String(statement, Py_eval_input, pdict, pdict));
    const char* cstr = PyUnicode_AsUTF8AndSize(ret, &size);
    std::string cpp = std::string(cstr, static_cast<size_t>(size));

    Py_Finalize();

    return cpp;
}