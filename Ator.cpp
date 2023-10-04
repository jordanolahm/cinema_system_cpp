#include "Ator.hpp"


Ator(const std::string& nome) : nome{nome} {}

const std::string& getNome() const { return nome; }