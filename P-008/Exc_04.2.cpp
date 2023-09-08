#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

char getRandomLowerCaseChar() {
    return 'a' + rand() % ('z' - 'a' + 1);
}

void capitalizeFirstChar(std::string &str) {
    if (!str.empty()) {
        str[0] = std::toupper(str[0]);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<std::string> stringsAleatorias(10);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            stringsAleatorias[i] += getRandomLowerCaseChar();
        }
        capitalizeFirstChar(stringsAleatorias[i]);
    }

    // Imprime as strings geradas
    for (int i = 0; i < 10; ++i) {
        std::cout << "String " << i + 1 << ": " << stringsAleatorias[i] << std::endl;
    }

    return 0;
}
