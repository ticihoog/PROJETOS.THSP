include <iostream>

using namespace std;

int insere_meio(int *vetor, int qtde, int elemento)
{
    int meio = qtde / 2;

    for (int i = qtde - 1; i >= meio; i--)
    {
        vetor[i + 1] = vetor[i];
    }

    vetor[meio] = elemento;
    return qtde + 1;
}

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6};
    int qtde = 6;
    qtde = insere_meio(vetor, qtde, 100);

    for (int i = 0; i < qtde; i++)
    {
        cout << vetor[i] << " ";
    }

    return 0;
}