#include <iostream>
#include <memory> // Para smart pointers
#include "Cinema.hpp" // Inclua os headers necessários
#include <stdexcept>

void exibirMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Cadastrar Sala\n";
    std::cout << "2. Listar Salas\n";
    std::cout << "3. Cadastrar Filme\n";
    std::cout << "4. Listar Filmes\n";
    std::cout << "5. Cadastrar Cliente\n";
    std::cout << "6. Listar Clientes\n";
    std::cout << "7. Cadastrar Sessao\n";
    std::cout << "8. Listar Sessoes\n";
    std::cout << "9. Vender Ingresso\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opcao: ";
}

int main() {
    // Crie instâncias dos gerenciadores e do cinema
   Cinema::Cinema()
    : gerenciadorFilmes(std::make_shared<GerenciadorFilmes>()),
      gerenciadorSalas(std::make_shared<GerenciadorSalas>()),
      gerenciadorClientes(std::make_shared<GerenciadorClientes>()),
      gerenciadorSessao(std::make_shared<GerenciadorSessao>()) {
    // Inicialize outras variáveis conforme necessário
    }

    char opcao;
    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                // Cadastrar Sala
                // Implemente a lógica aqui
                break;
            }
            case 2: {
                // Listar Salas
                // Implemente a lógica aqui
                break;
            }
            case 3: {
                // Cadastrar Filme
                // Implemente a lógica aqui
                break;
            }
            case 4: {
                // Listar Filmes
                // Implemente a lógica aqui
                break;
            }
            case 5: {
                // Cadastrar Cliente
                // Implemente a lógica aqui
                break;
            }
            case 6: {
                // Listar Clientes
                // Implemente a lógica aqui
                break;
            }
            case 7: {
                // Cadastrar Sessao
                // Implemente a lógica aqui
                break;
            }
            case 8: {
                // Listar Sessoes
                // Implemente a lógica aqui
                break;
            }
            case 9: {
                // Vender Ingresso
                // Implemente a lógica aqui
                break;
            }
            case 0: {
                std::cout << "Saindo do sistema.\n";
                break;
            }
            default: {
                std::cout << "Opcao invalida. Tente novamente.\n";
            }
        }

    } while (opcao != 0);

    return 0;
}