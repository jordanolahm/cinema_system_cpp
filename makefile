parametrosCompilacao=-Wall #-Wshadow
nomePrograma=aula

all: $(nomePrograma)

$(nomePrograma): main.o Ator.o Cinema.o Classificacao.o Cliente.o Filme.o Genero.o GerenciadorClientes.o GerenciadorFilmes.o GerenciadorSalas.o GerenciadorSessao.o Ingresso.o Sala.o Ingresso.o
	g++ -o $(nomePrograma) main.o Pessoa.o Disciplina.o SalaAula.o ConteudoMinistrado.o Console.o Professor.o ProfessorAdjunto.o Engenheiro.o ProfessorEngenheiro.o CPFInvalidoException.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Ator.o: Ator.hpp Ator.cpp
	g++ -c Ator.cpp $(parametrosCompilacao)

Cinema.o: Cinema.hpp Cinema.cpp
	g++ -c Cinema.cpp $(parametrosCompilacao)

Classificacao.o: Classificacao.hpp Classificacao.cpp
	g++ -c Classificacao.cpp $(parametrosCompilacao)

Cliente.o: Cliente.hpp Cliente.cpp
	g++ -c Cliente.cpp $(parametrosCompilacao)

Filme.o: Filme.hpp Filme.cpp
	g++ -c Filme.cpp $(parametrosCompilacao)

Genero.o: Genero.hpp Genero.cpp
	g++ -c Genero.cpp $(parametrosCompilacao)

GerenciadorClientes.o: GerenciadorClientes.hpp GerenciadorClientes.cpp
	g++ -c GerenciadorClientes.cpp $(parametrosCompilacao)

GerenciadorFilmes.o: GerenciadorFilmes.hpp GerenciadorFilmes.cpp
	g++ -c GerenciadorFilmes.cpp $(parametrosCompilacao)

GerenciadorSalas.o: GerenciadorSalas.hpp GerenciadorSalas.cpp
	g++ -c GerenciadorSalas.cpp $(parametrosCompilacao)

GerenciadorSessao.o: GerenciadorSessao.hpp GerenciadorSessao.cpp
	g++ -c GerenciadorSessao.cpp $(parametrosCompilacao)

Ingresso.o: Ingresso.hpp Ingresso.cpp
	g++ -c Ingresso.cpp $(parametrosCompilacao)	

Sala.o: Sala.hpp Sala.cpp
	g++ -c Sala.cpp $(parametrosCompilacao)	

Ingresso.o: Ingresso.hpp Ingresso.cpp
	g++ -c Ingresso.cpp $(parametrosCompilacao)	

clean:
	rm -f *.o *.gch $(nomePrograma)
