// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <iostream>

int main() {
    Py_Initialize();

    // Prepare global/locals dicts (can share)
    PyObject* globals = PyDict_New();
    PyObject* locals  = PyDict_New();

    // Optionally predefine helpers in the environment
    PyRun_String(
        "def add(a,b):\n"
        "    return a + b\n",
        Py_file_input, globals, locals
    );

    // Now evaluate a pure expression and capture its value
    PyObject* value = PyRun_String("add(7, 5)", Py_eval_input, globals, locals);
    if (!value) { PyErr_Print(); return 1; }

    long result = PyLong_AsLong(value);
    std::cout << "Result: " << result << "\n";

    Py_DECREF(value);
    Py_DECREF(globals);
    Py_DECREF(locals);
    Py_Finalize();
    return 0;
}
