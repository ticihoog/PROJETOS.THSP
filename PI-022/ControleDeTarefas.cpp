#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Tarefa {
public:
    Tarefa(const std::string& titulo, const std::string& descricao)
        : titulo(titulo), descricao(descricao), concluida(false) {}

    const std::string& getTitulo() const {
        return titulo;
    }

    const std::string& getDescricao() const {
        return descricao;
    }

    bool isConcluida() const {
        return concluida;
    }

    void marcarConcluida() {
        concluida = true;
    }

private:
    std::string titulo;
    std::string descricao;
    bool concluida;
};

class GerenciadorTarefas {
public:
    static void adicionarTarefa(const Tarefa& tarefa) {
        tarefas.push_back(tarefa);
    }

    static const std::vector<Tarefa>& getTarefas() {
        return tarefas;
    }

    static void listarTarefasPendentes() {
        for (const Tarefa& tarefa : tarefas) {
            if (!tarefa.isConcluida()) {
                std::cout << "Título: " << tarefa.getTitulo() << ", Descrição: " << tarefa.getDescricao() << std::endl;
            }
        }
    }

    static void marcarTarefaConcluida(const std::string& titulo) {
        for (Tarefa& tarefa : tarefas) {
            if (tarefa.getTitulo() == titulo) {
                tarefa.marcarConcluida();
                std::cout << "Tarefa marcada como concluída: " << titulo << std::endl;
                return;
            }
        }
        std::cout << "Tarefa não encontrada: " << titulo << std::endl;
    }

private:
    static std::vector<Tarefa> tarefas;
};

std::vector<Tarefa> GerenciadorTarefas::tarefas; // Inicialização estática

class BancoDeDados {
public:
    static void salvarTarefas(const std::string& nomeArquivo) {
        std::ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            for (const Tarefa& tarefa : GerenciadorTarefas::getTarefas()) {
                arquivo << tarefa.getTitulo() << ";" << tarefa.getDescricao() << ";" << tarefa.isConcluida() << "\n";
            }
            arquivo.close();
            std::cout << "Tarefas salvas no arquivo: " << nomeArquivo << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo para salvar tarefas." << std::endl;
        }
    }

    static void carregarTarefas(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            GerenciadorTarefas::getTarefas().clear(); // Limpar tarefas atuais
            std::string linha;
            while (getline(arquivo, linha)) {
                std::string titulo, descricao;
                bool concluida;
                std::istringstream linhaStream(linha);
                getline(linhaStream, titulo, ';');
                getline(linhaStream, descricao, ';');
                linhaStream >> concluida;
                Tarefa tarefa(titulo, descricao);
                if (concluida) {
                    tarefa.marcarConcluida();
                }
                GerenciadorTarefas::adicionarTarefa(tarefa);
            }
            arquivo.close();
            std::cout << "Tarefas carregadas do arquivo: " << nomeArquivo << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo para carregar tarefas." << std::endl;
        }
    }
};

int main() {
    BancoDeDados::carregarTarefas("tarefas.txt");

    while (true) {
        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Adicionar Tarefa\n";
        std::cout << "2. Listar Tarefas Pendentes\n";
        std::cout << "3. Marcar Tarefa como Concluída\n";
        std::cout << "4. Salvar Tarefas\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string titulo, descricao;
            std::cout << "Digite o título da tarefa: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Digite a descrição da tarefa: ";
            std::getline(std::cin, descricao);
            Tarefa tarefa(titulo, descricao);
            GerenciadorTarefas::adicionarTarefa(tarefa);
            std::cout << "Tarefa adicionada com sucesso." << std::endl;
        } else if (choice == 2) {
            GerenciadorTarefas::listarTarefasPendentes();
        } else if (choice == 3) {
            std::string titulo;
            std::cout << "Digite o título da tarefa a ser marcada como concluída: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            GerenciadorTarefas::marcarTarefaConcluida(titulo);
        } else if (choice == 4) {
            BancoDeDados::salvarTarefas("tarefas.txt");
        } else if (choice == 5) {
            BancoDeDados::salvarTarefas("tarefas.txt"); // Salvar antes de sair
            break;
        } else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
