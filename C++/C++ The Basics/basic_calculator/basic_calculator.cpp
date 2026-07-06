// g++ .\basic_calculator.cpp -o .\basic_calculator.exe | .\basic_calculator.exe

#include <iostream>
#include <string>

double plus (double first_number, double second_number) {
    return first_number + second_number;
}

double minus (double first_number, double second_number) {
    return first_number - second_number;
}

double mult (double first_number, double second_number) {
    return first_number * second_number;
}

double divi (double first_number, double second_number) {
    return first_number / second_number;
}

int main () {
    std::cout << "Basic Calculator: \n";

    double first_numer;
    double second_number;
    std::string logic;

    std::cout << "Enter the first number: ";
    std::cin >> first_numer;
    std::cout << "Enter the second number: ";
    std::cin >> second_number;
    std::cout << "Enter the logic (+, -, *, /): ";
    std::cin >> logic;

    if (logic == "+") {
        std::cout << plus(first_numer, second_number);
    }
    else if (logic == "-") {
        std::cout << minus(first_numer, second_number);
    }
    else if (logic == "*") {
        std::cout << mult(first_numer, second_number);
    }
    else if (logic == "/") {
        std::cout << divi(first_numer, second_number);
    }

    return 0;
}