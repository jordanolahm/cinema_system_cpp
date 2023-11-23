// Ingresso.cpp

#include "Ingresso.hpp"

namespace Cinema {

    Ingresso::Ingresso(std::shared_ptr<Sessao> sessao, std::shared_ptr<Cliente> cliente, EnumTipoIngresso tipo)
        : sessao(sessao), cliente(cliente), tipo(tipo) {}

    std::shared_ptr<Sessao> Ingresso::getSessao() const {
        return sessao;
    }

    std::shared_ptr<Cliente> Ingresso::getCliente() const {
        return cliente;
    }

    EnumTipoIngresso Ingresso::getTipo() const {
        return tipo;
    }

} // namespace Cinema