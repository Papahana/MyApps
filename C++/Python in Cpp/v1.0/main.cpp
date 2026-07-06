// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>

int main (int argc, char **argv) {

    Py_Initialize();
    PyRun_SimpleString("print('Hello World')");
    Py_Finalize();
    
    return 0;
}