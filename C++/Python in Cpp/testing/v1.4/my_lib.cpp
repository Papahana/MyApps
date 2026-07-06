#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <stdio.h>
#include "my_lib.h"
#include <string>
#include <iostream>

std::string my_func() {

    const char *py_script = 
        "import numpy as np\n"
        "arr = np.array([1, 2, 3, 4, 5])\n"
        "print(arr)\n";

    Py_Initialize();

    PyObject *pdict = PyDict_New();
    // PyRun_SimpleString(py_script);
    PyRun_String(py_script, Py_file_input , pdict, pdict);

    Py_Finalize();

    return "";
}