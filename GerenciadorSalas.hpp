#pragma once

#ifndef GERENCIADORSALAS_HPP
#define GERENCIADORSALAS_HPP

#include <memory>
#include <list>
#include <stdexcept>
#include <iostream>
#include "Sala.hpp"

namespace Cinema {

    class GerenciadorSalas {
    public:
        // construtor
        GerenciadorSalas(std::list<std::shared_ptr<Sala>> salas);
        
        // destrutor default
        virtual ~GerenciadorSalas() = default;
        
        //metodo para cadastrar sala
        virtual void cadastrarSala(std::shared_ptr<Sala> sala);
        
        //metodo que retorna todas as salas
        virtual std::list<std::shared_ptr<Sala>> listarTodasSalas() const;
        
        //metodo para remover sala
        virtual void removerSala( const unsigned int numero);

    private:
        //lista de salas cadastradas
        std::list<std::shared_ptr<Sala>> salas;
    };

} // namespace Cinema

#endif // GERENCIADORSALAS_HPP