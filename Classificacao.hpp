
#pragma once

#ifndef CINEMA_CLASSIFICACAO_HPP
#define CINEMA_CLASSIFICACAO_HPP

#include <iostream>
#include <string>

namespace Cinema {

    class Classificacao {
    public:
        // Construtor com initializer list
        Classificacao(unsigned int idadeMinima, const std::string& descricao);

        // Destrutor padrão
        ~Classificacao() = default;

        // Getters para idade mínima e descrição
        unsigned int getIdadeMinima() const;
        const std::string& getDescricao() const;

        // Setters para idade mínima e descrição
        void setIdadeMinima(unsigned int novaIdadeMinima);
        void setDescricao(const std::string& novaDescricao);

        // Sobrecarga do operador de saída para facilitar a exibição
        friend std::ostream& operator<<(std::ostream& os, const Classificacao& classificacao);

    private:
        unsigned int idadeMinima;
        std::string descricao;
    };

} // namespace Cinema

#endif // CINEMA_CLASSIFICACAO_HPP