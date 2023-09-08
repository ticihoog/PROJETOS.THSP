#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    return day <= daysInMonth[month];
}

std::string getMonthName(int month) {
    const char* monthNames[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    return monthNames[month - 1];
}

int main() {
    std::string data;
    std::cout << "Digite uma data no formato dd/mm/aaaa: ";
    std::cin >> data;

    int dia, mes, ano;
    sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);

    std::cout << "Dia: " << dia << std::endl;
    std::cout << "Mês: " << mes << std::endl;
    std::cout << "Ano: " << ano << std::endl;

    if (isValidDate(dia, mes, ano)) {
        std::cout << dia << " de " << getMonthName(mes) << " de " << ano << std::endl;
    } else {
        std::cout << "Data inválida." << std::endl;
    }

    return 0;
}
