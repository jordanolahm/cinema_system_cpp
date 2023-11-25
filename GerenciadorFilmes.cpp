#include "GerenciadorFilmes.hpp"

namespace Cinema {

    GerenciadorFilmes::GerenciadorFilmes(std::list<std::shared_ptr<Filme>> filmes)
        : filmes(filmes) {}

    GerenciadorFilmes::~GerenciadorFilmes() {}

    void GerenciadorFilmes::cadastrarFilme(std::shared_ptr<Filme> filme) {
        filmes.push_back(filme);
    }

    std::list<std::shared_ptr<Filme>> GerenciadorFilmes::listarTodosFilmes() {
        return filmes;
    }

    void GerenciadorFilmes::removerFilme(std::shared_ptr<Filme> filme) {
        try{
            std::list<std::shared_ptr<Filme>>::iterator it;

            for (it = filmes.begin(); it != filmes.end(); ++it) {
                if (*filme == *(*it)) {
                    it = filmes.erase(it);
                    break;
                }
            } 

            if (it == filmes.end()) {
                throw std::runtime_error("Cliente não encontrado para remoção.");
            }

            } catch (const std::exception& e) {
                std::cerr << "Erro ao remover filme: " << e.what() << std::endl;
                throw;
            }
    }


} // namespace Cinema