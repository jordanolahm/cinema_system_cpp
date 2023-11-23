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
        filmes.remove(filme);
    }


} // namespace Cinema