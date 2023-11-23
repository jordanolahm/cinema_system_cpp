#include "Cinema.hpp"

namespace Cinema {

    // Construtor com parâmetros
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
          gerenciadorSessao(gerenciadorSessao) {}

    // implementa destrutor
    Cinema::~Cinema() {}

    // Método para obter salas
    const std::list<std::shared_ptr<Sala>>& Cinema::obterSalas() const{
        return salas;
    }

    // Método para obter filmes
    const std::list<std::shared_ptr<Filme>>& Cinema::obterFilmes() const{
        return filmes;
    }

    // Método para obter sessões
    const std::list<std::shared_ptr<Sessao>>& Cinema::obterSessoes() const{
        return sessoes;
    }

    // Método para obter o gerenciador de salas
    std::shared_ptr<GerenciadorSalas> Cinema::obterGerenciadorSalas() {
        return gerenciadorSalas;
    }

    // Método para obter o gerenciador de filmes
    std::shared_ptr<GerenciadorFilmes> Cinema::obterGerenciadorFilmes() {
        return gerenciadorFilmes;
    }

    // Método para obter o gerenciador de clientes
    std::shared_ptr<GerenciadorClientes> Cinema::obterGerenciadorClientes() {
        return gerenciadorClientes;
    }

    // Método para obter o gerenciador de sessão
    std::shared_ptr<GerenciadorSessao> Cinema::obterGerenciadorSessao() {
        return gerenciadorSessao;
    }

} // namespace cinema