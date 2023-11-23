#pragma once

#ifndef GERENCIADORFILMES_HPP
#define GERENCIADORFILMES_HPP

#include <memory>
#include <list>
#include "Filme.hpp"

namespace Cinema {

    class GerenciadorFilmes {
    public:
        GerenciadorFilmes(std::list<std::shared_ptr<Filme>> filmes);
        virtual ~GerenciadorFilmes() = default;
        virtual void cadastrarFilme(std::shared_ptr<Filme> filme);
        virtual std::list<std::shared_ptr<Filme>> listarTodosFilmes();
        virtual void removerFilme(std::shared_ptr<Filme> filme);

    private:
        std::list<std::shared_ptr<Filme>> filmes;
    };

} // namespace Cinema

#endif // GERENCIADORFILMES_HPP