#include "GerenciadorClientes.hpp"

namespace Cinema {

    GerenciadorClientes::GerenciadorClientes(std::list<std::shared_ptr<Cliente>> clientes)
        : clientes(clientes) {
        // Construtor com initializer list
    }

    GerenciadorClientes::~GerenciadorClientes() {
        // Destrutor
    }

    void GerenciadorClientes::cadastrarCliente(std::shared_ptr<Cliente> cliente) {
        // Lógica para cadastrar um cliente
        clientes.push_back(cliente);
    }

    std::list<std::shared_ptr<Cliente>> GerenciadorClientes::listarTodosClientes() {
        // Retorna a lista de clientes
        return clientes;
    }

    void GerenciadorClientes::removerCliente(std::shared_ptr<Cliente> cliente) {
        // Lógica para remover um cliente
        clientes.remove(cliente);
    }


} // namespace Cinema