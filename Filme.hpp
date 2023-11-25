#pragma once
#ifndef FILME_HPP
#define FILME_HPP

#include <list>
#include <memory>
#include "Ator.hpp"
#include "Genero.hpp"
#include "Classificacao.hpp"
#include <iostream>
#include <stdexcept>


namespace Cinema {
    
    class Filme {

    public:
        Filme(const std::string& titulo, unsigned short duracao, std::unique_ptr<Genero> genero,  std::unique_ptr<Classificacao> classificacao,
              std::list<std::shared_ptr<Ator>> atores);

        //destrutor virtual
        virtual ~Filme() = default; 

        // Get - Utilização de smart pointer para evitar vazamento de memória
        std::string getTitulo() const;
        
        unsigned short getDuracao() const;
        
        std::unique_ptr<Genero>  getGenero() const;
        
        std::unique_ptr<Classificacao> getClassificacao() const;
        
        std::list<std::shared_ptr<Ator>> getAtores() const;
        
        //rankearFilme
        void rankear(unsigned short int nota); 

        //setNota
        void setNota(const unsigned short int nota);

        // Sobrecarga dos operadores de igualdade e desigualdade
        bool operator==(const Filme& outro) const;
        bool operator!=(const Filme& outro) const;

    private:
        //atributo titulo
        std::string titulo;
        // Duração em minutos
        unsigned short duracao; 
        // Genero
        std::unique_ptr<Genero> genero;
        
        //classificacao
        std::unique_ptr<Classificacao> classificacao; // Usando smart pointer para Classificacao
        
        //lista de atores
        std::list<std::shared_ptr<Ator>> atores;
        
        //nota
        unsigned short int notaFilme; 

        //Variavel de media para todos os objetos
        static unsigned int mediaRanking;
    };

} // namespace Cinema

#endif // FILME_HPP