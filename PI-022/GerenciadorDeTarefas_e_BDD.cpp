#include <vector>
#include <fstream>

class GerenciadorTarefas {
public:
    static void adicionarTarefa(const Tarefa& tarefa) {
        tarefas.push_back(tarefa);
    }

    static void listarTarefasPendentes() {
        for (const Tarefa& tarefa : tarefas) {
            if (!tarefa.isConcluida()) {
                // Imprimir informações da tarefa pendente
            }
        }
    }

    static void marcarTarefaConcluida(const std::string& titulo) {
        for (Tarefa& tarefa : tarefas) {
            if (tarefa.getTitulo() == titulo) {
                tarefa.marcarConcluida();
                break;
            }
        }
    }
private:
    static std::vector<Tarefa> tarefas;
};

class BancoDeDados {
public:
    static void salvarTarefas(const std::string& nomeArquivo) {
        std::ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            for (const Tarefa& tarefa : GerenciadorTarefas::getTarefas()) {
                arquivo << tarefa.getTitulo() << ";" << tarefa.getDescricao() << ";" << tarefa.isConcluida() << "\n";
            }
            arquivo.close();
        }
    }

    static void carregarTarefas(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            std::string linha;
            while (getline(arquivo, linha)) {
                // Processar cada linha do arquivo e criar objetos Tarefa
                // Adicionar as tarefas ao gerenciador de tarefas
            }
            arquivo.close();
        }
    }
};
