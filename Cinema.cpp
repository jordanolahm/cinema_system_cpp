#include "cinema.hpp"

Filme::Filme(const std::string& titulo, int duracao, Genero* genero)
    : titulo(titulo), duracao(duracao), genero(genero) {}

void Filme::adicionarAtor(Ator* ator, const std::string& papel) {
    elenco[ator] = papel;
}

Sala::Sala(int numero, int capacidade) : numero(numero), capacidade(capacidade) {}

Sessao::Sessao(Filme* filme, Sala* sala, const std::string& horario, int capacidade)
    : filme(filme), sala(sala), horario(horario), capacidade(capacidade), ingressosVendidos(0) {}

bool Sessao::venderIngresso(bool meioIngresso) {
    if (!sessaoEncerrada()) {
        ingressosVendidos++;
        return true;
    }
    return false;
}

Ingresso::Ingresso(Sessao* sessao, bool meioIngresso) : sessao(sessao), meioIngresso(meioIngresso) {}

Cinema::Cinema() {}

void Cinema::cadastrarFilme(const std::string& titulo, int duracao, Genero* genero) {
    filmes.emplace_back(titulo, duracao, genero);
}

void Cinema::cadastrarAtor(const std::string& nome) {
    atores.emplace_back(nome);
}

void Cinema::criarSala(int numero, int capacidade) {
    salas.emplace_back(numero, capacidade);
}

void Cinema::criarSessao(int filmeIndex, int salaIndex, const std::string& horario, int capacidade) {
    if (filmeIndex < 0 || filmeIndex >= filmes.size() ||
        salaIndex < 0 || salaIndex >= salas.size()) {
        std::cout << "Filme ou sala invalido." << std::endl;
        return;
    }

    sessoes.emplace_back(&filmes[filmeIndex], &salas[salaIndex], horario, capacidade);
}

void Cinema::venderIngresso(int sessaoIndex, bool meioIngresso) {
    if (sessaoIndex < 0 || sessaoIndex >= sessoes.size()) {
        std::cout << "Sessao invalida." << std::endl;
        return;
    }

    Sessao& sessao = sessoes[sessaoIndex];
    if (!sessao.sessaoEncerrada()) {
        ingressos.emplace_back(&sessao, meioIngresso);
        sessao.venderIngresso(meioIngresso);
    } else {
        std::cout << "Sessao encerrada. Nao e possivel comprar ingressos." << std::endl;
    }
}

void Cinema::listarSessoes() const {
    std::cout << "Lista de Sessoes:" << std::endl;
    for (size_t i = 0; i < sessoes.size(); ++i) {
        const Sessao& sessao = sessoes[i];
        std::cout << i + 1 << ". " << sessao.getHorario() << " - "
                  << sessao.getFilme()->getTitulo() << " - Sala "
                  << sessao.getSala()->getNumero() << " - Ingressos Vendidos: "
                  << sessao.getIngressosVendidos() << "/" << sessao.getCapacidade() << std::endl;
    }
}

void Cinema::listarFilmesPorGenero(const std::string& generoNome) const {
    std::cout << "Filmes do genero " << generoNome << ":" << std::endl;
    for (const Filme& filme : filmes) {
        if (filme.getGenero()->getNome() == generoNome) {
            std::cout << " - " << filme.getTitulo() << std::endl;
        }
    }
}