#include "Sala.hpp"

namespace Cinema {

    Sala::Sala(const unsigned int numero, unsigned int capacidade) : numero(numero), capacidade(capacidade) {
        if (capacidade == 0) {
            throw std::invalid_argument("A capacidade da sala deve ser maior que zero.");
        }
    }

    const unsigned int Sala::getNumero() const {
        return numero;
    }

    unsigned int Sala::getCapacidade() const {
        return capacidade;
    }

    void Sala::setCapacidade(unsigned int capacidade) {
        if (capacidade == 0) {
            throw std::invalid_argument("A capacidade da sala deve ser maior que zero.");
        }
        this->capacidade = capacidade;
    }


} // namespace Cinema