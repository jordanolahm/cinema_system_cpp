#include "Sessao.hpp"

namespace Cinema {

    // Construtor
    Sessao::Sessao(std::shared_ptr<Sala> sala, std::shared_ptr<Filme> filme, std::string horario,
                   unsigned int ingressosDisponiveis) : sala(sala), filme(filme), horario(std::move(horario)),
                ingressosDisponiveis(ingressosDisponiveis), status(EnumStatusSessao::ABERTA) {}

    // Getters
    std::string Sessao::getHorario() const {
        return horario;
    }

    EnumStatusSessao Sessao::getStatus() const {
        return status;
    }

    std::shared_ptr<Sala> Sessao::getSala() const {
        return sala;
    }

    std::shared_ptr<Filme> Sessao::getFilme() const {
        return filme;
    }

    // Métodos
    void Sessao::abrirSessao() {
        this->status = EnumStatusSessao::ABERTA;
    }

    void Sessao::lotarSessao() {
        this->status = EnumStatusSessao::LOTADA;
    }

    void Sessao::classificarFilme(std::shared_ptr<Filme> filme, unsigned short int nota) {
        try {
            filme->rankear(nota);
            std::cout << "Filme classificado com sucesso!\n";
        } catch (const std::out_of_range& e) {
            std::cerr << "Erro ao classificar o filme: " << e.what() << "\n";
            // Lógica adicional para lidar com a exceção, se necessário
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado ao classificar o filme: " << e.what() << "\n";
        }
    }

    int Sessao::getId() const {
        return identificador;
    }

    bool Sessao::verificarIngressosDisponiveis() {
        if(this->ingressosDisponiveis != 0) {
            return true; 
        }
        return false;
    }

    void Sessao::disponiblizarIngresso() {
        try {
            // Debita a quantidade de ingressos da sessão
            if (ingressosDisponiveis > 0 && status == EnumStatusSessao::ABERTA) {
                ingressosDisponiveis--;
                std::cout << "Ingresso comprado. Ingressos disponíveis na sessão: " << ingressosDisponiveis << std::endl;
            } else {
                this->lotarSessao();
                throw std::runtime_error("Não há ingressos disponíveis para a sessão.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao comprar ingresso: " << e.what() << std::endl;
        }
    }

    // Sobrecarga do operador de saída
    std::ostream& operator<<(std::ostream& os, const Sessao& sessao) {
        os << "Sessao: Filme: " << sessao.filme->getTitulo() << ", Sala: " << sessao.sala->getNumero() <<
           ", Horario: " << sessao.horario << "]";
        return os;
    }

} // namespace cinema