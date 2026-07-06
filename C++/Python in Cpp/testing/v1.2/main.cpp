// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <iostream>

int main (int argc, char*argv[]) {

    Py_Initialize();

    PyObject *name, *load_module, *func, *callfunc, *args;
    name = PyUnicode_FromString((char*)"script");
    load_module = PyImport_Import(name);

    func = PyObject_GetAttrString(load_module, (char*)"print_sentence");
    callfunc = PyObject_CallObject(func, NULL);
    bool fun1_out = PyFloat_AsDouble(callfunc);

    if (fun1_out) {
        std::cout << "C++: The function has been called and it shows no errors.";
    }

    std::cout << "\nPress ENTER to continue..."; std::cin.ignore();

    Py_Finalize();

    return 0;
}