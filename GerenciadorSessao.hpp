#pragma once

#ifndef GERENCIADORSESSAO_HPP
#define GERENCIADORSESSAO_HPP

#include <memory>
#include <list>
#include "Sessao.hpp"

namespace Cinema {

    class GerenciadorSessao {
    public:
        GerenciadorSessao(std::list<std::shared_ptr<Sessao>> sessoes);
        virtual ~GerenciadorSessao() = default;

        virtual void cadastrarSessao(std::shared_ptr<Sessao> sessao);
        virtual std::list<std::shared_ptr<Sessao>> listarTodasSessoes();
        virtual void removerSessao(std::shared_ptr<Sessao> sessao);

    private:
        std::list<std::shared_ptr<Sessao>> sessoes;
    };

} // namespace Cinema

#endif // GERENCIADORSESSAO_HPP