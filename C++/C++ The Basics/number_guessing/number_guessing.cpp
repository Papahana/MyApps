// g++ .\number_guessing.cpp -o .\number_guessing.exe | .\number_guessing.exe

#include <iostream>
#include <string>
#include <ctime>

int user_number;

int ask_user () {
    std::cout << "Introduce your number: ";
    std::cin >> user_number;
    return 0;
}

int main () {
    std::cout << "Generating random number ...\n";
    std::srand(std::time(0));
    int random_num = rand() % 10 + 1;  // range 1 to 10

    do {
        ask_user();
        if (user_number < random_num) {
            std::cout << "Number must be greater.\n";
        }
        else if (user_number > random_num) {
            std::cout << "Number must be lower.\n";
        }
    }
    while (user_number != random_num);

    std::cout << "Game finished ...";

    return 0;
}