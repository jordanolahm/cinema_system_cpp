#pragma once

#ifndef SALA_HPP
#define SALA_HPP

#include <iostream>
#include <stdexcept>
#include <list>

namespace Cinema {

    class Sala {

    public:
        Sala(const unsigned int numero, unsigned int capacidade);

        const unsigned int getNumero() const;
        unsigned int getCapacidade() const;
        
        void setCapacidade(unsigned int capacidade);
        
        
    private:
        const unsigned int numero;
        unsigned int capacidade;
    };

} // namespace Cinema

#endif // SALA_HPP