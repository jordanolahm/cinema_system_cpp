#include "GerenciadorSalas.hpp"

namespace Cinema {

    GerenciadorSalas::GerenciadorSalas(std::list<std::shared_ptr<Sala>> salas)
        : salas(salas) {}

    GerenciadorSalas::~GerenciadorSalas() {}

    void GerenciadorSalas::cadastrarSala(std::shared_ptr<Sala> sala){
        salas.push_back(sala);
    }

    std::list<std::shared_ptr<Sala>> GerenciadorSalas::listarTodasSalas() const {
        return salas;
    }

    void GerenciadorSalas::removerSala( const unsigned int numero) {
        try {
            std::list<std::shared_ptr<Sala>>::iterator it = salas.begin();
            while (it != salas.end()) {
                if ((*it)->getNumero() == numero) {
                    it = salas.erase(it);
                    break;
                } else {
                    ++it;
                }
            }

            if (it == salas.end()) {
                throw std::runtime_error("Sala não encontrada para remoção.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao remover sala: " << e.what() << std::endl;
            throw;
        }
    }


} // namespace Cinema