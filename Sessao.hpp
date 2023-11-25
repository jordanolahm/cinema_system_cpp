#pragma once

#include <string>
#include <list>
#include <memory>
#include "Sala.hpp"
#include "Filme.hpp"
#include "Ingresso.hpp"
#include "Genero.hpp"
#include "Classificacao.hpp"
#include "Cliente.hpp"
#include <stdexcept>
#include <iostream>
#include "EnumStatusSessao.hpp"


namespace Cinema {
    class Sessao {
    public:
        // Construtor
        Sessao(std::shared_ptr<Sala> sala, std::shared_ptr<Filme> filme, std::string horario,
            unsigned int ingressosDisponiveis, unsigned int identificador);

        // Getters
        std::string getHorario() const;

        std::string setHorario(const std::string& novoHorario) const; 
        
        EnumStatusSessao getStatus() const;
        
        std::shared_ptr<Sala> getSala() const;

        std::shared_ptr<Filme> getFilme() const;

        // Método para abrir sessao e aplicar status
        void abrirSessao();
        
        // Método para lotar sessao
        void lotarSessao();

        // Metodo para classificar filme
        void classificarFilme(std::shared_ptr<Filme> filme, unsigned short int nota);

        // Sobrecarga do operador de saída
        friend std::ostream& operator<<(std::ostream& os, const Sessao& sessao);

        //obter identificador
        unsigned int  getId() const;

        //verifica ingresso disponivel
        bool verificarIngressosDisponiveis();

        //vender ingresso
        void disponiblizarIngresso();

        //atualiza ingressos com base na capacidade da sala
        void ajustarIngressosDisponiveis(); 


    private:
        // Ponteiro sala
        std::shared_ptr<Sala> sala;
        
        //Ponteiro Filme
        std::shared_ptr<Filme> filme;
        
        // horario sessao
        std::string horario;
        
        //quantidade de ingressos disponiveis
        unsigned int ingressosDisponiveis;

        //status sessao
        EnumStatusSessao status;
        
        //identificador sessao
        unsigned int identificador; 

        // Lista de ingressos vendidos
        std::list<Ingresso> ingressos;

        // Classificação do filme
        std::shared_ptr<Classificacao> classificacao;

        // Clientes que compraram ingressos
        std::list<std::shared_ptr<Cliente>> clientes;

    };

} // namespace cinema