#include "Filme.hpp"

namespace Cinema {

    unsigned int Filme::mediaRanking = 7;

    Filme::Filme(const std::string& titulo, unsigned short duracao, std::unique_ptr<Genero> genero,
                 std::unique_ptr<Classificacao> classificacao, std::list<std::shared_ptr<Ator>> atores)
        : titulo(titulo), duracao(duracao), genero(std::move(genero)), classificacao(std::move(classificacao)), atores(std::move(atores)), notaFilme(0) {}

    std::string Filme::getTitulo() const {
        return titulo;
    }

    unsigned short Filme::getDuracao() const {
        return duracao;
    }

    std::unique_ptr<Genero> Filme::getGenero() const {
        return std::make_unique<Genero>(*genero);
    }

    std::unique_ptr<Classificacao> Filme::getClassificacao() const {
        return std::make_unique<Classificacao>(*classificacao);
    }

    std::list<std::shared_ptr<Ator>> Filme::getAtores() const {
        return atores;
    }

    void Filme::setNota(const unsigned short int nota) {
        this->notaFilme = nota;
    }

    void Filme::rankear(unsigned short int nota) {
        try {
            if (nota < 0 || nota > 10) {
                throw std::out_of_range("A nota deve estar no intervalo de 0 a 10.");
            }

            this->setNota(nota);

            // Compare com a média padrão
            if (nota > mediaRanking) {
                std::cout << "O filme está acima da média padrão.\n";
            }
            
        } catch (const std::out_of_range& e) {
            std::cerr << "Erro ao classificar o filme: " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado ao classificar o filme: " << e.what() << "\n";
        }
    }

} // namespace Cinema