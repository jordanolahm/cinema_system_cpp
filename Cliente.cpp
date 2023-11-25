#include "Cliente.hpp"

namespace Cinema {

    Cliente::Cliente(const std::string& nome, unsigned short int idade, const uint64_t cpf)
        : nome(nome), idade(idade), cpf(cpf) {}

    // Getters
    std::string Cliente::getNome() const {
        return nome;
    }

    unsigned short int Cliente::getIdade() const {
        return idade;
    }

    uint64_t Cliente::getCpf() const {
        return cpf;
    }

    void Cliente::setNome(const std::string& nome) {
        this->nome = nome;
    }

    void Cliente::setIdade(const unsigned short int idade) {
        this->idade = idade;
    }


    void Cliente::setCpf(const uint64_t cpf) {
        this->cpf = cpf;
    }

    // Métodos
    void Cliente::comprarIngresso(std::shared_ptr<Sessao> sessao, std::shared_ptr<Ingresso> ingressos) {
        try {
            // Verificar se há ingressos disponíveis na sessão
            if (sessao->verificarIngressosDisponiveis() && sessao) {
                //Atualizar a sessão para refletir a venda do ingresso
                sessao->disponiblizarIngresso();
                //Adiciono ingresso na lista
                ingressosAdquiridos.push_back(std::make_shared<Ingresso>());
                //Mensagem de sucesso
                std::cout << "Ingresso comprado com sucesso para a sessão de ID " << sessao->getId() << ".\n";
            } else {
                // Lançar uma exceção personalizada se não houver assentos disponíveis
                throw std::runtime_error("Erro ao comprar ingresso: Existe algum problema com a sessão, verifique os ingressos disponíveis.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao comprar ingresso: " << e.what() << std::endl;
        } catch (const std::logic_error& e) {
            std::cerr << "Erro lógico ao comprar ingresso: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado ao comprar ingresso: " << e.what() << std::endl;
        }
    }

    std::list<std::shared_ptr<Ingresso>> Cliente::listarIngressos() const {
        try {
            if (ingressosAdquiridos.empty()) {
                throw std::runtime_error("A lista de ingressos adquiridos está vazia.");
            }
            return ingressosAdquiridos;

        } catch (const std::exception& e) {
            std::cerr << "Erro ao listar ingressos: " << e.what() << std::endl;
            return {};
        }
    }

    
    bool Cliente::operator==(const Cliente& outro) const {
        return cpf == outro.cpf;
    }

    bool Cliente::operator!=(const Cliente& outro) const {
        return !(*this == outro);
    }

} // namespace Cinema