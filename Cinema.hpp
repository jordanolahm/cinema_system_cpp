#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Ator {
public:
    Ator(const std::string& nome) : nome(nome) {}
    const std::string& getNome() const { return nome; }

private:
    std::string nome;
};

class Genero {
public:
    Genero(const std::string& nome) : nome(nome) {}
    const std::string& getNome() const { return nome; }

private:
    std::string nome;
};

class Filme {
public:
    Filme(const std::string& titulo, int duracao, Genero* genero);
    const std::string& getTitulo() const { return titulo; }
    int getDuracao() const { return duracao; }
    const Genero* getGenero() const { return genero; }
    void adicionarAtor(Ator* ator, const std::string& papel);

private:
    std::string titulo;
    int duracao;
    Genero* genero;
    std::unordered_map<Ator*, std::string> elenco;
};

class Sala {
public:
    Sala(int numero, int capacidade);
    int getNumero() const { return numero; }
    int getCapacidade() const { return capacidade; }

private:
    int numero;
    int capacidade;
};

class Sessao {
public:
    Sessao(Filme* filme, Sala* sala, const std::string& horario, int capacidade);
    const Filme* getFilme() const { return filme; }
    const Sala* getSala() const { return sala; }
    const std::string& getHorario() const { return horario; }
    int getCapacidade() const { return capacidade; }
    int getIngressosVendidos() const { return ingressosVendidos; }
    bool sessaoEncerrada() const { return ingressosVendidos >= capacidade; }
    bool venderIngresso(bool meioIngresso);

private:
    Filme* filme;
    Sala* sala;
    std::string horario;
    int capacidade;
    int ingressosVendidos;
};

class Ingresso {
public:
    Ingresso(Sessao* sessao, bool meioIngresso);
    const Sessao* getSessao() const { return sessao; }
    bool isMeioIngresso() const { return meioIngresso; }

private:
    Sessao* sessao;
    bool meioIngresso;
};

class Cinema {
public:
    Cinema();
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