// g++ .\pass_generator.cpp -o .\pass_generator.exe | .\pass_generator.exe

#include <iostream>
#include <string>
#include <ctime>

int main () {
    std::string letters[71] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","z","1","2","3","4","5","6","7","8","9","+","-","*","!","·","$","%","&","=","?","¿","}","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    std::string password;

    int cycle = 8;
    std::srand(std::time(0));
    while (cycle > 0) {
        password = password + letters[rand() % 71 + 1];
        --cycle;
    }

    std::cout << password;

    return 0;
}