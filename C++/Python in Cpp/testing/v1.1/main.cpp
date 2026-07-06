// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <iostream>

int main (int argc, char*argv[]) {

    Py_Initialize();
    
    PyObject *name, *load_module, *func, *callfunc, *args;
    name = PyUnicode_FromString((char*)"script");
    load_module = PyImport_Import(name);

    func = PyObject_GetAttrString(load_module, (char*)"fun1");
    callfunc = PyObject_CallObject(func, NULL);
    double fun1_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module, (char*)"fun2");
    args = PyTuple_Pack(1, PyFloat_FromDouble(3.0));
    callfunc = PyObject_CallObject(func,args);
    double fun2_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module, (char*)"fun3");
    args = PyTuple_Pack(2, PyFloat_FromDouble(3.0), PyFloat_FromDouble(4.0));
    callfunc = PyObject_CallObject(func, args);
    double fun3_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module, (char*)"fun4");
    args = PyTuple_Pack(1, PyUnicode_FromString((char*)"Ruben"));
    callfunc = PyObject_CallObject(func, args);
    std::string fun4_out = _PyUnicode_AsString(callfunc);

    Py_Finalize();
    
    std::cout << fun1_out << "\n";
    std::cout << fun2_out << "\n";
    std::cout << fun3_out << "\n";
    std::cout << fun4_out << "\n";

}