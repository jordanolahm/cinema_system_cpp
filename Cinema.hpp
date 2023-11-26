#pragma once

#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <list>
#include <memory>
#include "Sala.hpp"
#include "Filme.hpp"
#include "Sessao.hpp"
#include "Cliente.hpp"
#include "GerenciadorFilmes.hpp"
#include "GerenciadorSalas.hpp"
#include "GerenciadorClientes.hpp"
#include "GerenciadorSessao.hpp"

namespace Cinema {
class Cinema {

    public:
        Cinema(std::list<std::shared_ptr<Sala>>& salas,
               std::list<std::shared_ptr<Filme>>& filmes,
               std::list<std::shared_ptr<Sessao>>& sessoes,
               std::shared_ptr<GerenciadorFilmes>& gerenciadorFilmes,
               std::shared_ptr<GerenciadorSalas>& gerenciadorSalas,
               std::shared_ptr<GerenciadorClientes>& gerenciadorClientes,
               std::shared_ptr<GerenciadorSessao>& gerenciadorSessao);

        // Destrutor padrão
        virtual ~Cinema() = default;

        const std::list<std::shared_ptr<Sala>>& obterSalas() const;
        const std::list<std::shared_ptr<Filme>>& obterFilmes() const;
        const std::list<std::shared_ptr<Sessao>>& obterSessoes() const;
        std::shared_ptr<GerenciadorSalas> obterGerenciadorSalas();
        std::shared_ptr<GerenciadorFilmes> obterGerenciadorFilmes();
        std::shared_ptr<GerenciadorClientes> obterGerenciadorClientes();
        std::shared_ptr<GerenciadorSessao> obterGerenciadorSessao();

    private:
        std::list<std::shared_ptr<Sala>> salas;
        std::list<std::shared_ptr<Filme>> filmes;
        std::list<std::shared_ptr<Sessao>> sessoes;
        std::shared_ptr<GerenciadorFilmes> gerenciadorFilmes;
        std::shared_ptr<GerenciadorSalas> gerenciadorSalas;
        std::shared_ptr<GerenciadorClientes> gerenciadorClientes;
        std::shared_ptr<GerenciadorSessao> gerenciadorSessao;
};

}

#endif // CINEMA_HPP