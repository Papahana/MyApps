// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <iostream>

int main() {
    Py_Initialize();

    // Ensure current dir in sys.path
    PyRun_SimpleString("import sys, os; sys.path.insert(0, os.getcwd())");

    PyObject* pName = PyUnicode_FromString("mymod");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "add");
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* pArgs = PyTuple_Pack(2, PyLong_FromLong(7), PyLong_FromLong(5));
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue) {
                long result = PyLong_AsLong(pValue);
                std::cout << "Result from Python: " << result << "\n";
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pFunc);
        }
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
    }

    Py_Finalize();
    return 0;
}
