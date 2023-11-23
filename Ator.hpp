#pragma once

#ifndef ATOR_HPP
#define ATOR_HPP

#include <iostream>
#include <list>

namespace Cinema {

    class Ator {
        public:
            Ator(std::string nome, std::string papel);
            virtual ~Ator() = default;

            std::string getNome() const;
            std::string getPapel() const;

            void setNome(const std::string& nome);
            void setPapel(const std::string& papel);

        private:
            std::string nome;
            std::string papel;
        };

} // namespace Cinema

#endif // ATOR_HPP