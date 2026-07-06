// g++ -c my_lib.cpp -o my_lib.o
// ar rcs libmy_lib.a my_lib.o
// g++ main.cpp -o main.exe -L. -lmy_lib -L C:\Users\ruben\AppData\Local\Programs\Python\Python313\libs -lpython313 -I C:\Users\ruben\AppData\Local\Programs\Python\Python313\include
// ./main.exe

#include "my_lib.h"
#include <iostream>
#include <string>

int main() {

    std::cout << "Return int from Python: " << return_int(18) << "\n";
    std::cout << "Return str from Python: " << return_str("Texto") << "\n";

    std::cout << "\nPress ENTER to continue..."; std::cin.ignore();

    return 0;
}
