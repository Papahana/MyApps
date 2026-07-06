// g++ main.cpp -o main -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// .\main.exe

#include <C:\Users\ruben\AppData\Local\Programs\Python\Python313\include\Python.h>
#include <iostream>
#include <stdio.h>

int main (int argc, char **argv) {

    const char *text = 
        "print ('Hello World from Python Script')\n"
        "x = 1\n"
        "y = 2\n"
        "print('Prueba de operación: 1 + 2 = ' + str(x + y))\n";

    Py_Initialize();
    PyRun_SimpleString(text);
    Py_Finalize();
    
    std::cout << "\nPress ENTER to continue..."; std::cin.ignore();

    return 0;
}