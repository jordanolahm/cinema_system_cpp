#pragma once

#ifndef GERENCIADORSESSAO_HPP
#define GERENCIADORSESSAO_HPP

#include <memory>
#include <list>
#include <stdexcept>
#include <iostream>
#include "Sessao.hpp"

namespace Cinema {

    class GerenciadorSessao {
    public:

        //construtor
        GerenciadorSessao(std::list<std::shared_ptr<Sessao>> sessoes);
        //destrutor padrão
        virtual ~GerenciadorSessao() = default;

        //cadastrar uma sessão para armazenar na lista de sessões
        virtual void cadastrarSessao(std::shared_ptr<Sessao> sessao);

        //listar todas sessões contidas no cinema
        virtual std::list<std::shared_ptr<Sessao>> listarTodasSessoes();

        //remover uma sessão da lista
        virtual void removerSessao(unsigned int identificador);

    private:
        // lista de sessões apontando para sessão
        std::list<std::shared_ptr<Sessao>> sessoes;
    };

} // namespace Cinema

#endif // GERENCIADORSESSAO_HPP