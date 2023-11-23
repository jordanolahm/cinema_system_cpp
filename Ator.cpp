#include "Ator.hpp"

namespace Cinema {

    Ator::Ator(std::string nome, std::string papel) : nome(nome), papel(papel) {}

    Ator::~Ator() {}

    std::string Ator::getNome() const {
        return this->nome;
    }

    std::string Ator::getPapel() const {
        return this->papel;
    }

    void Ator::setNome(const std::string& nome) {
        this->nome = nome;
    }

    void Ator::setPapel(const std::string& papel) {
        this->papel = papel;
    }


} // namespace Cinema