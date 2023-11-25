#include "Sessao.hpp"

namespace Cinema {

    // Construtor
    Sessao::Sessao(std::shared_ptr<Sala> sala, std::shared_ptr<Filme> filme, std::string horario,
                   unsigned int ingressosDisponiveis, unsigned int identificador) : sala(sala), filme(filme), horario(horario),  ingressosDisponiveis(sala->getCapacidade()), status(EnumStatusSessao::ABERTA), identificador(identificador) {
        try {
            if (!sala) {
                throw std::invalid_argument("Sessao: Sala inválida.");
            }

            if (this->ingressosDisponiveis <= 0) {
                throw std::invalid_argument("Sessao: A quantidade de ingressos deve ser maior que zero.");
            }

            // Verifica se a quantidade de ingressos é maior que a capacidade da sala
            if (this->ingressosDisponiveis > sala->getCapacidade()) {
                throw std::invalid_argument("Sessao: A quantidade de ingressos não pode ser maior que a capacidade da sala.");
            }

        } catch (const std::exception& e) {
            std::cerr << "Erro ao criar a sessao: " << e.what() << std::endl;
        }
    }

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
        if (status == EnumStatusSessao::LOTADA) {
            this->status = EnumStatusSessao::ABERTA;
        } else {
            throw std::logic_error("A sessao já esta aberta.");
        }
    }

    void Sessao::lotarSessao() {
        if (status == EnumStatusSessao::ABERTA) {
            this->status = EnumStatusSessao::LOTADA;
        } else {
            throw std::logic_error("A sessao nao esta aberta para lotação.");
        }
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

    unsigned int Sessao::getId() const {
        return identificador;
    }

    bool Sessao::verificarIngressosDisponiveis() {
        if(ingressosDisponiveis != 0) {
            return true; 
        }
        return false;
    }

    void Sessao::disponiblizarIngresso() {
        try {
            // Debita a quantidade de ingressos da sessão
            if (ingressosDisponiveis > 0 && this->status == EnumStatusSessao::ABERTA) {
                ingressosDisponiveis--;
                std::cout << "Ingresso comprado. Ingressos disponíveis na sessão: " << this->ingressosDisponiveis << std::endl;
            } else {
                this->lotarSessao();
                throw std::runtime_error("Não há ingressos disponíveis para a sessão.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao comprar ingresso: " << e.what() << std::endl;
        }
    }
    //
    void Sessao::ajustarIngressosDisponiveis() {
        try {
            if (!sala) {
                throw std::invalid_argument("Sessao: problemas ao acessar as informações de sala.");
            }
            this->ingressosDisponiveis = sala->getCapacidade();
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro ao ajustar ingressos disponíveis: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado ao ajustar ingressos disponíveis: " << e.what() << std::endl;
        }
    }       

    // Sobrecarga do operador de saída
    std::ostream& operator<<(std::ostream& os, const Sessao& sessao) {
        os << "Sessao: Filme: " << sessao.filme->getTitulo() << ", Sala: " << sessao.sala->getNumero() <<
           ", Horario: " << sessao.horario << "]";
        return os;
    }

} // namespace cinema