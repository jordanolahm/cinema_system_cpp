#include <iostream>
#include <memory>
#include <list>
#include "Cinema.hpp"
#include <limits>

using namespace Cinema;
using namespace std;

// Função para exibir o menu de operações para o GerenciadorSalas
void menuGerenciadorSalas(Cinema& cinema) {
    int escolha;

    do {
        cout << "\nMenu de Operações para Salas:\n";
        cout << "1. Listar Salas\n";
        cout << "2. Cadastrar Nova Sala\n";
        cout << "3. Remover Sala\n";
        cout << "4. Voltar ao Menu Principal\n";

        cout << "Escolha uma opção: ";

        while (!(cin >> escolha)) {
            cout << "Entrada inválida. Por favor, digite um número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        try {
            switch (escolha) {
                case 1: {
                    // Listar Salas
                    auto listaSalas = cinema.obterGerenciadorSalas()->listarTodasSalas();
                    cout << "Lista de Salas:\n";
                    for (const auto& sala : listaSalas) {
                        // Exibir informações relevantes de cada sala
                    }
                    break;
                }
                case 2: {
                    // Cadastrar Nova Sala
                    cinema.obterGerenciadorSalas()->cadastrarSala(make_shared<Sala>());
                    break;
                }
                case 3: {
                    // Remover Sala
                    unsigned int numeroSala;
                    cout << "Digite o número da sala a ser removida: ";
                    while (!(cin >> numeroSala)) {
                        cout << "Entrada inválida. Por favor, digite um número: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cinema.obterGerenciadorSalas()->removerSala(numeroSala);
                    break;
                }
                case 4: {
                    cout << "Voltando ao Menu Principal...\n";
                    break;
                }
                default: {
                    cout << "Opção inválida. Tente novamente.\n";
                }
            }
        } catch (const exception& e) {
            cerr << "Erro: " << e.what() << endl;
        }

    } while (escolha != 4);
}

// Adicione funções semelhantes para os outros gerenciadores

int main() {
    // Inicializar listas e gerenciadores (substitua com a lógica real)
    list<shared_ptr<Sala>> salas;
    list<shared_ptr<Filme>> filmes;
    list<shared_ptr<Sessao>> sessoes;

    shared_ptr<GerenciadorFilmes> gerenciadorFilmes = make_shared<GerenciadorFilmes>(filmes);
    shared_ptr<GerenciadorSalas> gerenciadorSalas = make_shared<GerenciadorSalas>(salas);
    shared_ptr<GerenciadorClientes> gerenciadorClientes = make_shared<GerenciadorClientes>();
    shared_ptr<GerenciadorSessao> gerenciadorSessao = make_shared<GerenciadorSessao>(sessoes, gerenciadorFilmes, gerenciadorSalas);

    // Inicializar a instância do Cinema
    Cinema cinema(salas, filmes, sessoes, gerenciadorFilmes, gerenciadorSalas, gerenciadorClientes, gerenciadorSessao);

    int escolha;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Operações para Salas\n";
        cout << "2. Operações para Filmes\n";
        cout << "3. Operações para Clientes\n";
        cout << "4. Operações para Sessões\n";
        cout << "5. Sair\n";

        cout << "Escolha uma opção: ";

        while (!(cin >> escolha)) {
            cout << "Entrada inválida. Por favor, digite um número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        try {
            switch (escolha) {
                case 1: {
                    // Submenu para gerenciar salas
                    menuGerenciadorSalas(cinema);
                    break;
                }
                // Casos 2, 3, e 4 para os outros gerenciadores
                case 2: {
                    // Submenu para gerenciar filmes
                    // Implemente chamadas para funções relacionadas a filmes
                    break;
                }
                case 3: {
                    // Submenu para gerenciar clientes
                    // Implemente chamadas para funções relacionadas a clientes
                    break;
                }
                case 4: {
                    // Submenu para gerenciar sessões
                    // Implemente chamadas para funções relacionadas a sessões
                    break;
                }
                case 5: {
                    cout << "Saindo...\n";
                    break;
                }
                default: {
                    cout << "Opção inválida. Tente novamente.\n";
                }
            }
        } catch (const exception& e) {
            cerr << "Erro: " << e.what() << endl;
        }

    } while (escolha != 5);

    return 0;
}