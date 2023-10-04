#ifndef CINEMA_HPP
#define CINEMA_HPP

// import STL libs

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

//import libs 

#include "Ator.hpp"
#include "Filme.hpp"
#include "Sala.hpp"
#include "Sessao.hpp"
#include "Ingresso.hpp"
#include "Genero.hpp"

class Cinema {

public:
    //construtor
    Cinema();

    //destrutor
    ~Cinema(); 
    
    void cadastrarFilme(const std::string& titulo, int duracao, Genero* genero);
    void cadastrarAtor(const std::string& nome);
    void criarSala(int numero, int capacidade);
    void criarSessao(int filmeIndex, int salaIndex, const std::string& horario, int capacidade);
    void venderIngresso(int sessaoIndex, bool meioIngresso);
    void listarSessoes() const;
    void listarFilmesPorGenero(const std::string& generoNome) const;

private:
    std::vector<Filme> filmes;
    std::vector<Ator> atores;
    std::vector<Genero> generos;
    std::vector<Sala> salas;
    std::vector<Sessao> sessoes;
    std::vector<Ingresso> ingressos;
};

#endif // CINEMA_HPP