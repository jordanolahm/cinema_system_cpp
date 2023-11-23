#include "Genero.hpp"

namespace Cinema {
    // Construtor
    Genero::Genero(std::string nome)
        : nome(nome) {}

    // Getter
    std::string Genero::getNome() const {
        return nome;
    }

    // Setter
    void Genero::setNome(const std::string& novoNome) {
        this->nome = novoNome;
    }

    // Sobrecarga do operador de saída
    std::ostream& operator<<(std::ostream& os, const Genero& genero) {
        os << "Nome do Gênero: " << genero.nome;
        return os;
    }

} // namespace cinema