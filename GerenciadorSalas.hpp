#pragma once

#ifndef GERENCIADORSALAS_HPP
#define GERENCIADORSALAS_HPP

#include <memory>
#include <list>
#include "Sala.hpp"

namespace Cinema {

    class GerenciadorSalas {
    public:
        GerenciadorSalas(std::list<std::shared_ptr<Sala>> salas);
        virtual ~GerenciadorSalas() = default;
        virtual void cadastrarSala(std::shared_ptr<Sala> sala);
        virtual std::list<std::shared_ptr<Sala>> listarTodasSalas();
        virtual void removerSala(std::shared_ptr<Sala> sala);

    private:
        std::list<std::shared_ptr<Sala>> salas;
    };

} // namespace Cinema

#endif // GERENCIADORSALAS_HPP