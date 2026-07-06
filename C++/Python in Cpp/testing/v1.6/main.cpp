// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <iostream>
#include <string>

int main() {

    const char* setup =
        "def greet(name):\n"
        "    return f'Hello, {name}!'\n";

    Py_Initialize();

    PyObject *pdict = PyDict_New();
    Py_ssize_t size = 0;

    PyRun_String(setup, Py_file_input, pdict, pdict);

    PyObject* ret = PyObject_Str(PyRun_String("greet('Ruben')", Py_eval_input, pdict, pdict));

    const char* cstr = PyUnicode_AsUTF8AndSize(ret, &size);

    std::string cpp = std::string(cstr, static_cast<size_t>(size));
    std::cout << cpp << "\n";

    Py_Finalize();

    return 0;
}

