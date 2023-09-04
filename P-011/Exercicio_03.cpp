#include <iostream>

// Função para ordenar quatro variáveis float em ordem crescente
void ordenar(float &a, float &b, float &c, float &d) {
    float temp;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }

    if (a > d) {
        temp = a;
        a = d;
        d = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    if (b > d) {
        temp = b;
        b = d;
        d = temp;
    }

    if (c > d) {
        temp = c;
        c = d;
        d = temp;
    }
}

int main() {
    float num1, num2, num3, num4;

    std::cout << "Digite quatro números float: ";
    std::cin >> num1 >> num2 >> num3 >> num4;

    ordenar(num1, num2, num3, num4);

    std::cout << "Números ordenados em ordem crescente: " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << std::endl;

    return 0;
}
