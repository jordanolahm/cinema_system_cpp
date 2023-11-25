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
        
        //construtor, recebendo lista de clientes
        GerenciadorClientes(std::list<std::shared_ptr<Cliente>> clientes);
        
        //define destrutor
        virtual ~GerenciadorClientes() = default;
        
        //metodo cadastrar cliente
        virtual void cadastrarCliente(std::shared_ptr<Cliente> cliente);
        
        //listar clientes cadastrados
        virtual std::list<std::shared_ptr<Cliente>> listarTodosClientes();
        
        //remover cliente
        virtual void removerCliente(std::shared_ptr<Cliente> cliente);

        //remove cliente pelo CPF
        virtual void removerClientePorCPF( uint64_t cpf);

    private:
        //lista de clientes
        std::list<std::shared_ptr<Cliente>> clientes;
    };

} // namespace Cinema

#endif // GERENCIADORCLIENTES_HPP