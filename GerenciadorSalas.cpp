#include "GerenciadorSalas.hpp"

namespace Cinema {

    GerenciadorSalas::GerenciadorSalas(std::list<std::shared_ptr<Sala>> _salas)
        : salas(_salas) {}

    GerenciadorSalas::~GerenciadorSalas() {}

    void GerenciadorSalas::cadastrarSala(std::shared_ptr<Sala> sala) {
        salas.push_back(sala);
    }

    std::list<std::shared_ptr<Sala>> GerenciadorSalas::listarTodasSalas() {
        return salas;
    }

    void GerenciadorSalas::removerSala(std::shared_ptr<Sala> sala) {
        salas.remove(sala);
    }


} // namespace Cinema