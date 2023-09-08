#include <iostream>
#include <string>

using namespace std;

struct Produto {
    string codigo;
    string nome;
    float preco;
};

Produto produtos[300];
int numProdutos = 0;

void inserirProduto() {
    Produto novoProduto;
    cout << "Digite o código do produto: ";
    cin >> novoProduto.codigo;
    
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == novoProduto.codigo) {
            cout << "Este código já existe, tente novamente." << endl;
            return;
        }
    }
    
    cout << "Digite o nome do produto: ";
    cin >> novoProduto.nome;
    
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].nome == novoProduto.nome) {
            cout << "Este nome já existe, tente novamente." << endl;
            return;
        }
    }
    
    cout << "Digite o preço do produto: ";
    cin >> novoProduto.preco;
    
    produtos[numProdutos] = novoProduto;
    numProdutos++;
}

void excluirProduto() {
    string codigoExcluido;
    cout << "Digite o código do produto que deseja excluir: ";
    cin >> codigoExcluido;
    
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigoExcluido) {
            for (int j = i; j < numProdutos - 1; j++) {
                produtos[j] = produtos[j+1];
            }
            numProdutos--;
            cout << "Produto excluído com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Produto não encontrado." << endl;
}

void listarProdutos() {
    for (int i = 0; i < numProdutos; i++) {
        cout << produtos[i].codigo << " - " << produtos[i].nome << " - R$" << produtos[i].preco << endl;
    }
}

void consultarPreco() {
    string codigoConsulta;
    cout << "Digite o código do produto que deseja consultar o preço: ";
    cin >> codigoConsulta;
    
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigoConsulta) {
            cout << "O preço do produto " << produtos[i].nome << " é R$" << produtos[i].preco << endl;
            return;
        }
    }
    
    cout << "Produto não encontrado." << endl;
}

int main() {
    int opcao = 0;
    
    while (opcao != 5) {
        cout << "Selecione uma opção:" << endl
             << "1. Inserir um novo produto" << endl
             << "2. Excluir um produto cadastrado" << endl
             << "3. Listar todos os produtos" << endl
             << "4. Consultar o preço de um produto" << endl
             << "5. Sair" << endl;
             
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                inserirProduto();
                break;
            case 2:
                excluirProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                consultarPreco();
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida, tente novamente." << endl;
                break;
        }
    }
    
    return 0;

}