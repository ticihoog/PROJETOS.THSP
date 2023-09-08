#include <iostream>

// Função para converter temperatura de Celsius para Fahrenheit
double converterCelsiusParaFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Função para lidar com entrada/saída
void processarConversao() {
    double temperaturaCelsius;
    
    std::cout << "Digite uma temperatura em graus Celsius: ";
    std::cin >> temperaturaCelsius;
    
    double temperaturaFahrenheit = converterCelsiusParaFahrenheit(temperaturaCelsius);
    
    std::cout << "Temperatura em Fahrenheit: " << temperaturaFahrenheit << " °F" << std::endl;
}

int main() {
    processarConversao();
    
    return 0;
}
