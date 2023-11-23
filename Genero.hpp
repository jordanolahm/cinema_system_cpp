#pragma once

#include <iostream>
#include <stdexcept>

namespace Cinema {

    class Genero {
        public:
            // Construtor
            Genero(std::string nome);

            // Getter
            std::string getNome() const;

            // Setter
            void setNome(const std::string& novoNome);

            // Sobrecarga do operador de saída
            friend std::ostream& operator<<(std::ostream& os, const Genero& genero);

        private:
            std::string nome;
    };

} // namespace cinema