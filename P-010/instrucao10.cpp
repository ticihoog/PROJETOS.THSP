#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int limite_alunos;
    cout << "Informe o limite de alunos: ";
    cin >> limite_alunos;
    vector < string > nomes;
    vector < float > notas1;
    vector < float > notas2;

    for (int i =0; i < limite_alunos; i++ ) {
        string nome;
        float nota1, nota2; 
        cout << "Informe o nome do aluno " << i+1 << ": ";
        cin >> nota1;
        notas1.push_back (nota1);
        cout << "Informe a segunda nota do aluno " << i+1 << ": ";
        cin >> nota2;
        notas2.push_back (nota2);

    }
    for (int i=0; i< limite_alunos; i++) {

        cout << "Aluno: " << nomes [i] << ", Nota1:\n" << notas1 [i] << ", Nota2: " << notas2[i] << endl;

    }
    return 0;

}