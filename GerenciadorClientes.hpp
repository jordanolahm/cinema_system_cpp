// GerenciadorClientes.hpp
#pragma once

#ifndef GERENCIADORCLIENTES_HPP
#define GERENCIADORCLIENTES_HPP

#include <memory>
#include <list>
#include "Cliente.hpp"

namespace Cinema {
    class GerenciadorClientes {
    public:
        GerenciadorClientes(std::list<std::shared_ptr<Cliente>> clientes);
        virtual ~GerenciadorClientes() = default;

        virtual void cadastrarCliente(std::shared_ptr<Cliente> cliente);
        virtual std::list<std::shared_ptr<Cliente>> listarTodosClientes();
        virtual void removerCliente(std::shared_ptr<Cliente> cliente);

    private:
        std::list<std::shared_ptr<Cliente>> clientes;
    };

} // namespace Cinema

#endif // GERENCIADORCLIENTES_HPP