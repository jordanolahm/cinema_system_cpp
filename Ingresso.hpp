#pragma once

#ifndef INGRESSO_HPP
#define INGRESSO_HPP

#include <memory>
#include "Sessao.hpp"
#include "Cliente.hpp"
#include <stdexcept>
#include <iostream>
#include "EnumTipoIngresso.hpp"

namespace Cinema {
    class Ingresso {
    
    public:
        Ingresso(std::shared_ptr<Sessao> sessao, std::shared_ptr<Cliente> cliente, const EnumTipoIngresso tipo);
        
        // Getters
        std::shared_ptr<Sessao> getSessao() const;
        std::shared_ptr<Cliente> getCliente() const;
        EnumTipoIngresso getTipo() const;

    private:
        //sessao 
        std::shared_ptr<Sessao> sessao;
        //cliente
        std::shared_ptr<Cliente> cliente;    
        //enum tipo 
        EnumTipoIngresso tipo;
    };

} // namespace Cinema

#endif // INGRESSO_HPP