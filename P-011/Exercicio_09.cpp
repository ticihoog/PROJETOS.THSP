#include <iostream>

float calc_serie(int N) {
    float S = 0.0;
    
    for (int i = 1; i <= N; i++) {
        S += 1.0/i;
    }
    
    return S;
}

int main() {
    int N = 10;
    
    float resultado = calc_serie(N);
    
    std::cout << "Valor de S: " << resultado;
    
    return 0;
}