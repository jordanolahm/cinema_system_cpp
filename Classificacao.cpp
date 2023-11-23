#include "Classificacao.hpp"

namespace Cinema {

    // Construtor com initializer list
    Classificacao::Classificacao(unsigned int idadeMinima, const std::string& descricao)
        : idadeMinima(idadeMinima), descricao(descricao) {}

    //destrutor
    Classificacao::~Classificacao() = default;

    // Getters para idade mínima e descrição
    unsigned int Classificacao::getIdadeMinima() const {
        return idadeMinima;
    }

    const std::string& Classificacao::getDescricao() const {
        return descricao;
    }

    // Setters para idade mínima e descrição
    void Classificacao::setIdadeMinima(unsigned int novaIdadeMinima) {
        this->idadeMinima = novaIdadeMinima;
    }

    void Classificacao::setDescricao(const std::string& novaDescricao) {
        this->descricao = novaDescricao;
    }

    // Sobrecarga do operador de saída para facilitar a exibição
    std::ostream& operator<<(std::ostream& os, const Classificacao& classificacao) {
        os << "Idade Mínima: " << classificacao.getIdadeMinima() << ", Descrição: " << classificacao.getDescricao();
        return os;
    }

} // namespace Cinema