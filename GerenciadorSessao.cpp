#include "GerenciadorSessao.hpp"

namespace Cinema {

    GerenciadorSessao::GerenciadorSessao(std::list<std::shared_ptr<Sessao>> sessoes)
        : sessoes(sessoes) {}

    GerenciadorSessao::~GerenciadorSessao() {}

    void GerenciadorSessao::cadastrarSessao(std::shared_ptr<Sessao> sessao) {
        sessoes.push_back(sessao);
    }

    std::list<std::shared_ptr<Sessao>> GerenciadorSessao::listarTodasSessoes() {
        return sessoes;
    }

    void GerenciadorSessao::removerSessao(std::shared_ptr<Sessao> sessao) {
        sessoes.remove(sessao);
    }


} // namespace Cinema