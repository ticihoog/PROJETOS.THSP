#include <string>

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
