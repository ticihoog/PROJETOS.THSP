#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
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
    srand(time(nullptr));

    std::string str1, str2;

    for (int i = 0; i < 10; i++) {
        str1 += getRandomLowerCaseChar();
        str2 += getRandomLowerCaseChar();
    }

    capitalizeFirstChar(str1);
    capitalizeFirstChar(str2);

    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;

    // Ordenar as strings em ordem alfabética
    std::string strings[] = {str1, str2};
    std::sort(strings, strings + 2);

    std::cout << "Strings em ordem alfabética:" << std::endl;
    for (const std::string &s : strings) {
        std::cout << s << std::endl;
    }

    return 0;
}
