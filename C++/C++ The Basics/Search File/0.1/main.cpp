#include <iostream>
#include <string>
#include <filesystem>
#include "termcolor/termcolor.hpp"

int main () {

    std::cout << termcolor::green << "\n" << "Search file" << termcolor::white;
    std::cout << "\n\n - Enter file name: ";
    std::string file_name;
    std::cin >> file_name;
    std::cout << " - Enter drive letter: ";
    std::string drive_letter;
    std::cin >> drive_letter;

    std::string searchDir = drive_letter + ":\\"; // or "C:\\" with double backslashes or "." to search in current directory

    std::cout << "\n";
    for (const auto& entry : std::filesystem::recursive_directory_iterator(searchDir,
                             std::filesystem::directory_options::skip_permission_denied)) {
        if (entry.path().filename() == file_name) {
            // std::cout << "Found: " << entry.path() << "\n";
            std::string path_string{entry.path().u8string()}; 
            std::cout << "Found: " << path_string.substr(0, path_string.find(".")) << "\n";
        }
    }

    std::cout << "\n";
    return 0;
}
