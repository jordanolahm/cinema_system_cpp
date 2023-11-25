#include "Cinema.hpp"

namespace Cinema {

    // Construtor
    Cinema::Cinema(std::list<std::shared_ptr<Sala>>& salas,
                   std::list<std::shared_ptr<Filme>>& filmes,
                   std::list<std::shared_ptr<Sessao>>& sessoes,
                   std::shared_ptr<GerenciadorFilmes>& gerenciadorFilmes,
                   std::shared_ptr<GerenciadorSalas>& gerenciadorSalas,
                   std::shared_ptr<GerenciadorClientes>& gerenciadorClientes,
                   std::shared_ptr<GerenciadorSessao>& gerenciadorSessao)
        : salas(salas),
          filmes(filmes),
          sessoes(sessoes),
          gerenciadorFilmes(gerenciadorFilmes),
          gerenciadorSalas(gerenciadorSalas),
          gerenciadorClientes(gerenciadorClientes),
          gerenciadorSessao(gerenciadorSessao) {
    }

    const std::list<std::shared_ptr<Sala>>& Cinema::obterSalas() const {
        return salas;
    }

    const std::list<std::shared_ptr<Filme>>& Cinema::obterFilmes() const {
        return filmes;
    }

    const std::list<std::shared_ptr<Sessao>>& Cinema::obterSessoes() const {
        return sessoes;
    }

    std::shared_ptr<GerenciadorSalas> Cinema::obterGerenciadorSalas() {
        return gerenciadorSalas;
    }

    std::shared_ptr<GerenciadorFilmes> Cinema::obterGerenciadorFilmes() {
        return gerenciadorFilmes;
    }

    std::shared_ptr<GerenciadorClientes> Cinema::obterGerenciadorClientes() {
        return gerenciadorClientes;
    }

    std::shared_ptr<GerenciadorSessao> Cinema::obterGerenciadorSessao() {
        return gerenciadorSessao;
    }

} // namespace Cinema