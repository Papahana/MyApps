// g++ -c math.cpp -o math.o
// ar rcs libmath.a math.o
// g++ main.cpp -L. -lmath -o main.exe
// ./main.exe

#include "math.h"
#include <iostream>

int main() {
    int a = 10, b = 5;

    std::cout << "Addition: " << add(a, b) << "\n";
    std::cout << "Subtraction: " << subtract(a, b) << "\n";

    std::cout << "\nPress ENTER to continue..."; std::cin.ignore();

    return 0;
}