#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
    int dia, mes, ano;

public:
    
    static int compara(Data d1, Data d2) {
        if (d1.ano < d2.ano) return -1;
        if (d1.ano > d2.ano) return 1;
        if (d1.mes < d2.mes) return -1;
        if (d1.mes > d2.mes) return 1;
        if (d1.dia < d2.dia) return -1;
        if (d1.dia > d2.dia) return 1;
        return 0;
    }

    Data(int _dia, int _mes, int _ano) {
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }
    string toString() {
        string ret = "";
        ret.append(to_string(dia));
        ret.append("/");
        ret.append(to_string(mes));
        ret.append("/");
        ret.append(to_string(ano));
        return ret;
    }
};

class Lista {
public:
    virtual void entradaDeDados() = 0;
    virtual void mostraMediana() = 0;
    virtual void mostraMenor() = 0;
    virtual void mostraMaior() = 0;
};

class ListaNomes : public Lista {
    vector<string> lista;

public:
    void entradaDeDados() {
        int n;
        cout << "Quantos nomes deseja inserir na lista? ";
        cin >> n;
        cin.ignore(); 
        for (int i = 0; i < n; i++) {
            string nome;
            cout << "Digite o Nome " << (i + 1) << ": ";
            getline(cin, nome);
            lista.push_back(nome);
        }
    }

    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            cout << "---------------------------------------------" << endl << "Segue análise de dados:" << endl << "Mediana: " << lista[meio] << endl;
        }
    }

    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Menor nome: " << lista[0] << endl;
        }
    }

    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.rbegin(), lista.rend());
            cout << "Maior nome: " << lista[0] << endl;
        }
    }
};

class ListaDatas : public Lista {
    vector<Data> lista;

public:
    void entradaDeDados() {
        int n;
        cout << "Quantas datas deseja inserir na lista? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite a Data " << (i + 1) << " (Dia Mês Ano - Ex: 21 04 1988): ";
            cin >> dia >> mes >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }

    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end(), [](const Data &d1, const Data &d2) {
                return Data::compara(d1, d2) < 0;
            });
            int meio = lista.size() / 2;
            cout << "Mediana: " << lista[meio].toString() << endl;
        }
    }

    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end(), [](const Data &d1, const Data &d2) {
                return Data::compara(d1, d2) < 0;
            });
            cout << "Menor data: " << lista[0].toString() << endl;
        }
    }

    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.rbegin(), lista.rend(), [](const Data &d1, const Data &d2) {
                return Data::compara(d1, d2) < 0;
            });
            cout << "Maior data: " << lista[0].toString() << endl;
        }
    }
};

class ListaSalarios : public Lista {
    vector<float> lista;

public:
    void entradaDeDados() {
        int n;
        cout << "Quantos salários deseja inserir na lista? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            float salario;
            cout << "Digite o Salário (sem vírgula)" << (i + 1) << ": ";
            cin >> salario;
            lista.push_back(salario);
        }
    }

    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            if (lista.size() % 2 == 0) {
                float mediana = (lista[meio - 1] + lista[meio]) / 2.0;
                cout << "Mediana: " << mediana << endl;
            } else {
                cout << "Mediana: " << lista[meio] << endl;
            }
        }
    }

    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Menor salário: " << lista[0] << endl;
        }
    }

    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.rbegin(), lista.rend());
            cout << "Maior salário: " << lista[0] << endl;
        }
    }
};

class ListaIdades : public Lista {
    vector<int> lista;

public:
    void entradaDeDados() {
        int n;
        cout << "Quantas idades deseja inserir na lista? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int idade;
            cout << "Idade " << (i + 1) << ": ";
            cin >> idade;
            lista.push_back(idade);
        }
    }

    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            if (lista.size() % 2 == 0) {
                int valor1 = lista[meio - 1];
                int valor2 = lista[meio];
                float mediana = static_cast<float>(valor1 + valor2) / 2;
                cout << "Mediana: " << mediana << endl;
            } else {
                cout << "Mediana: " << lista[meio] << endl;
            }
        }
    }

    void mostraMenor() {
        if (!lista.empty()) {
            sort(lista.begin(), lista.end());
            cout << "Menor idade: " << lista[0] << endl;
        }
    }

    void mostraMaior() {
        if (!lista.empty()) {
            sort(lista.rbegin(), lista.rend());
            cout << "Maior idade: " << lista[0] << endl;
        }
    }
};

int main() {
    vector<Lista*> listaDeListas;

    ListaNomes listaNomes;
    listaNomes.entradaDeDados();
    listaDeListas.push_back(&listaNomes);

    ListaDatas listaDatas;
    listaDatas.entradaDeDados();
    listaDeListas.push_back(&listaDatas);

    ListaSalarios listaSalarios;
    listaSalarios.entradaDeDados();
    listaDeListas.push_back(&listaSalarios);

    ListaIdades listaIdades;
    listaIdades.entradaDeDados();
    listaDeListas.push_back(&listaIdades);

    for (Lista* l : listaDeListas) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
    }

    return 0;
}
