// g++ .\dice_rolling.cpp -o .\dice_rolling.exe | .\dice_rolling.exe

#include <iostream>
#include <string>
#include <ctime>

int main () {
    std::cout << "Roll the dice when ready (y/n) ";

    std::string trigger;
    std::cin >> trigger;

    int random_num;
    std::srand(std::time(0));
    if (trigger == "y") {
        random_num = rand() % 20;
        std::cout << "  - Your random number is: " << random_num;
    }

    return 0;
}