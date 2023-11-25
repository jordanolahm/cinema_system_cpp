#pragma once

#include <string>
#include <list>
#include "Genero.hpp"
#include "Sessao.hpp"
#include "Ingresso.hpp"
#include <cstdint>
#include <iostream>
#include <stdexcept>


namespace Cinema {

    class Cliente {

    public:
        Cliente(const std::string& nome, unsigned short int idade, const uint64_t cpf);

        // Getters
        std::string getNome() const;
        unsigned short int getIdade() const;
        uint64_t getCpf() const;

        // Setters
        void setCpf( const uint64_t cpf);
        void setNome(const std::string& nome);
        void setIdade(const unsigned short int idade);

        // Comprar ingressos
        void comprarIngresso(std::shared_ptr<Sessao> sessao, std::shared_ptr<Ingresso> ingressos);
        
        //listar ingressos
        std::list<std::shared_ptr<Ingresso>> listarIngressos() const;

        // Sobrecarga dos operadores de igualdade e desigualdade
        bool operator==(const Cliente& outro) const;
        bool operator!=(const Cliente& outro) const;

    private:
        std::string nome;
        unsigned short int idade;
        uint64_t cpf;
        std::list<std::shared_ptr<Ingresso>> ingressosAdquiridos;
    };

} // namespace Cinema