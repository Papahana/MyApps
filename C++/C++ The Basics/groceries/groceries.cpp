// g++ .\groceries.cpp -o .\groceries.exe | .\groceries.exe

#include <iostream>
#include <string>

int main () {
    std::string str = "Fruit: Orange";
    std::string row1 = " - Amount _______ ";
    int amount = 12;
    std::string row2 = " - Price ________ ";
    double price = 9.99;
    std::string row3 = " - Aviailable ___ ";
    bool available = true;

    std::cout << str << "\n";
    std::cout << row1 << amount << "\n";
    std::cout << row2 << price << "\n";
    std::cout << row3 << available << "\n";

    std::string user_input;
    std::cout << "Do you want to buy? (y/n) ";
    std::cin >> user_input;

    return 0;
}