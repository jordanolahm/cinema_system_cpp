#include "GerenciadorClientes.hpp"

namespace Cinema {

    GerenciadorClientes::GerenciadorClientes(std::list<std::shared_ptr<Cliente>> clientes)
        : clientes(clientes) {
        // Construtor com initializer list
    }

    GerenciadorClientes::~GerenciadorClientes() {}

    void GerenciadorClientes::cadastrarCliente(std::shared_ptr<Cliente> cliente) {
        clientes.push_back(cliente);
    }

    std::list<std::shared_ptr<Cliente>> GerenciadorClientes::listarTodosClientes() {
         try {
            // Verificar se a lista está vazia
            if (clientes.empty()) {
                throw std::runtime_error("A lista de clientes está vazia.");
            }
            return clientes;
        } catch (const std::exception& e) {
            std::cerr << "Erro ao listar todos os clientes: " << e.what() << std::endl;
            throw;
        }
    }

    void GerenciadorClientes::removerCliente(std::shared_ptr<Cliente> cliente) {
          try{
            //define iterator
            std::list<std::shared_ptr<Cliente>>::iterator it;

            for (; it != clientes.end(); ++it) {
                if (*cliente == *(*it)) {
                    it = clientes.erase(it);
                    break;
                }
            }
            
            if (it == clientes.end()) {
                throw std::runtime_error("Cliente não encontrado para remoção.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao remover cliente: " << e.what() << std::endl;
            throw; 
        }
    }

    void GerenciadorClientes::removerClientePorCPF(const uint64_t cpf) {
        try {
            //define iterator
            std::list<std::shared_ptr<Cliente>>::iterator it;
            
            while(it != clientes.end()) {
                if ((*it)->getCpf() == cpf) {
                    it = clientes.erase(it);  
                } else {
                    ++it;  //mais eficiente que it++
                }
            }

            if (clientes.empty()) {
                throw std::runtime_error("Cliente não encontrado para remoção.");
            }
        } catch (const std::exception& e) {
            // Melhorar a mensagem de erro e repropagar a exceção
            std::cerr << "Erro ao remover cliente: " << e.what() << std::endl;
            throw;  // Repropagar a exceção após o tratamento
        }
    }

} // namespace Cinema