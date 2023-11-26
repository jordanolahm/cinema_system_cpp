#include "GerenciadorSessao.hpp"

namespace Cinema {

    GerenciadorSessao::GerenciadorSessao(std::list<std::shared_ptr<Sessao>> sessoes)
        : sessoes(sessoes) {}

    GerenciadorSessao::~GerenciadorSessao() {}

    void GerenciadorSessao::cadastrarSessao(std::shared_ptr<Sessao> sessao) {
        try {
            if (!sessao) {
                throw std::invalid_argument("Erro ao cadastrar uma sessao nula.");
            }
            sessoes.push_back(sessao);
        } catch (const std::exception& e) {
            std::cerr << "Erro ao cadastrar sessao: " << e.what() << std::endl;
            throw;
        }
    }

    std::list<std::shared_ptr<Sessao>> GerenciadorSessao::listarTodasSessoes() {
        return this->sessoes;
    }
    
    void GerenciadorSessao::removerSessao(unsigned int identificador) {
        try {
            auto it = sessoes.begin();
            while (it != sessoes.end()) {
                if ((*it)->getId() == identificador) {
                    it = sessoes.erase(it);
                    break;
                } else {
                    ++it;
                }
            }

            if (it == sessoes.end()) {
                throw std::runtime_error("Sessao não encontrada para remoção.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao remover sessao: " << e.what() << std::endl;
            throw;
        }
    }


} // namespace Cinema