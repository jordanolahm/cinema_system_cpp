#include "cinema.hpp"
#include "ator.hpp"

int main() {
    Cinema cinema;

    Genero acao("Acao");
    Genero comedia("Comedia");

    cinema.cadastrarFilme("Filme A", 120, &acao);
    cinema.cadastrarFilme("Filme B", 90, &comedia);

    cinema.cadastrarAtor("Ator 1");
    cinema.cadastrarAtor("Ator 2");

    cinema.criarSala(1, 50);
    cinema.criarSala(2, 30);

    cinema.criarSessao(0, 0, "10:00", 50);
    cinema.criarSessao(1, 1, "15:00", 30);

    cinema.venderIngresso(0, true);
    cinema.venderIngresso(0, false);
    cinema.venderIngresso(1, false);

    cinema.listarSessoes();
    cinema.listarFilmesPorGenero("Comedia");

    return 0;
}