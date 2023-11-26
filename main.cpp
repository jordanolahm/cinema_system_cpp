#include <iostream>
#include <memory>
#include <list>
#include "Cinema.hpp"

using namespace Cinema;

int main() {
    try {
        //criando estrutura principal
        std::list<std::shared_ptr<Sala>> salas;
        std::list<std::shared_ptr<Filme>> filmes;
        std::list<std::shared_ptr<Sessao>> sessoes;
        std::shared_ptr<GerenciadorFilmes> gerenciadorFilmes = std::make_shared<GerenciadorFilmes>(filmes);
        std::shared_ptr<GerenciadorSalas> gerenciadorSalas = std::make_shared<GerenciadorSalas>(salas);
        std::shared_ptr<GerenciadorClientes> gerenciadorClientes = std::make_shared<GerenciadorClientes>();
        std::shared_ptr<GerenciadorSessao> gerenciadorSessao = std::make_shared<GerenciadorSessao>(sessoes);

        // Criando uma instância do cinema
        Cinema::Cinema cinema(salas, filmes, sessoes, gerenciadorFilmes, gerenciadorSalas, gerenciadorClientes, gerenciadorSessao);

        // Menu principal
        int escolha;
        bool sairSubMenu = false; 
        while (!sairSubMenu) {
            std::cout << "------ Menu Principal ------" << std::endl;
            std::cout << "1. Gerenciar Salas" << std::endl;
            std::cout << "2. Gerenciar Filmes" << std::endl;
            std::cout << "3. Gerenciar Sessões" << std::endl;
            std::cout << "4. Gerenciar Clientes" << std::endl;
            std::cout << "5. Encerrar Programa" << std::endl;
            std::cout << "Escolha uma opção: ";
            std::cin >> escolha;

            switch (escolha) {
                case 1:
                    // Submenu para o gerenciamento de salas
                    int opcaoSala;
                    bool sairSubMenuSala = false;
                    while (!sairSubMenuSala) {
                        std::cout << "------ Gerenciar Salas ------" << std::endl;
                        std::cout << "1. Cadastrar Sala" << std::endl;
                        std::cout << "2. Listar Salas" << std::endl;
                        std::cout << "3. Remover Sala" << std::endl;
                        std::cout << "4. Voltar ao Menu Principal" << std::endl;
                        std::cout << "Escolha uma opção: ";
                        std::cin >> opcaoSala;

                        switch (opcaoSala) {
                            case 1:
                                    try {
                                    // Solicitar dados da sala ao usuário
                                    unsigned int _numero, _capacidade;
                                    std::cout << "Informe o número da sala: ";
                                    std::cin >>  _numero;
                                    std::cout << "Informe a capacidade da sala: ";
                                    std::cin >> _capacidade;

                                    // Criar uma nova sala
                                    std::shared_ptr<Sala> novaSala = std::make_shared<Sala>( _numero, _capacidade);

                                    // Adicionar a sala ao gerenciador de salas
                                    cinema.obterGerenciadorSalas()->cadastrarSala(novaSala);
                                    std::cout << "Sala cadastrada com sucesso!" << std::endl;
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao cadastrar sala: " << e.what() << std::endl;
                                }
                                break;
                            case 2:
                                    try {
                                    // Obter a lista de salas do gerenciador e verificar se está vazia
                                    auto listaSalas = cinema.obterGerenciadorSalas()->listarTodasSalas();
                                    if (listaSalas.empty()) {
                                        std::cout << "Nenhuma sala cadastrada." << std::endl;
                                    } else {
                                        std::cout << "Listando as salas...." << std::endl;
                                        for (const auto& sala : listaSalas) {
                                            std::cout << "Número: " << sala->getNumero() << ", Capacidade: " << sala->getCapacidade() << std::endl;
                                        }
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao listar salas: " << e.what() << std::endl;
                                }
                                break;
                            case 3:
                                    try {
                                    unsigned int _numero;
                                    std::cout << "Informe o número da sala a ser removida: ";
                                    std::cin >> _numero;

                                    // instancia as classes para retorno do dado de sala
                                    auto gerenciadorSalas = cinema.obterGerenciadorSalas();
                                    auto listaSalas = gerenciadorSalas->listarTodasSalas();

                                    bool salaEncontrada = false;
                                    // sala recebe o tipo elemento ListaSalas
                                    for (const auto& sala : listaSalas) {
                                        if (sala->getNumero() == _numero) {
                                            salaEncontrada = true;
                                            break;
                                        }
                                    }
                                    if (salaEncontrada) {
                                        gerenciadorSalas->removerSala(_numero);
                                        std::cout << "Sala removida com sucesso!" << std::endl;
                                    } else {
                                        std::cout << "Sala com número " << _numero << " não encontrada." << std::endl;
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao remover sala: " << e.what() << std::endl;
                                }
                                break;
                            case 4:
                                std::cout << "Voltando ao Menu Principal." << std::endl;
                                sairSubMenuSala = true;
                                break;
                            default:
                                std::cout << "Opção inválida. Tente novamente." << std::endl;
                                break;
                        }
                    }
                    break;
                case 2:
                    int opcaoFilme;
                    bool sairSubMenuFilme = false;
                    while (!sairSubMenuFilme) {
                        std::cout << "------ Gerenciar Filme ------" << std::endl;
                        std::cout << "1. Cadastrar Filme" << std::endl;
                        std::cout << "2. Listar Filmes" << std::endl;
                        std::cout << "3. Remover Filme"<< std::endl;
                        std::cout << "4. Voltar ao Menu Principal"<< std::endl;
                        std::cout << "Escolha a opção: ";
                        std::cin >> opcaoFilme;
                     
                        switch (opcaoFilme) {
                            case 1: // Cadastrar Filme
                                try {
                                    //Criar as variaveis para filme Cinema->GerenciadorFilme->filme
                                    std::string _titulo;
                                    unsigned short _duracao;
                                    unsigned int _idadeMinima;
                                    std::string _descricao;
                                    std::string _nomeGenero;

                                    // Entrada de dados
                                    std::cout << "Informe o título do filme: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, _titulo);
                                    std::cout << "Informe a duração do filme em minutos: ";
                                    std::cin >> _duracao;
                                    std::cout << "Informe a idade mínima para assistir: ";
                                    std::cin >> _idadeMinima;
                                    std::cout << "Informe a descrição da classificação: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, _descricao);
                                    
                                    std::cout << "Informe o nome do gênero do filme: ";
                                    std::cin >> _nomeGenero;

                                    std::unique_ptr<Genero> _genero = std::make_unique<Genero>(_nomeGenero);
                                    std::unique_ptr<Classificacao> _classificacao = std::make_unique<Classificacao>(_idadeMinima, _descricao);

                                    // Lista de atores
                                    std::list<std::shared_ptr<Ator>> _atores;

                                    // Entrada de atores
                                    int _numeroAtores;
                                    std::cout << "Informe o número de atores no filme: ";
                                    std::cin >> _numeroAtores;

                                    for (int i = 0; i < _numeroAtores; ++i) {
                                        std::string _nomeAtor, _papelAtor;
                                        std::cout << "Informe o nome do ator #" << i + 1 << ": ";
                                        std::cin.ignore();
                                        std::getline(std::cin, _nomeAtor);
                                        std::cout << "Informe o papel do ator #" << i + 1 << ": ";
                                        std::getline(std::cin, _papelAtor);

                                        auto ator = std::make_shared<Ator>(_nomeAtor, _papelAtor);
                                        _atores.push_back(ator);
                                    }
                                    //Constroi um novo filme para atualizar a lista de filmes
                                    std::shared_ptr<Filme> _novoFilme = std::make_shared<Filme>(_titulo, _duracao, std::move(_genero), std::move(_classificacao), _atores);
                                    
                                    //acessa o cadastro de filme passando novo filme

                                    cinema.obterGerenciadorFilmes()->cadastrarFilme(_novoFilme);
                                    
                                    std::cout << "Filme cadastrado com sucesso!" << std::endl;
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao cadastrar filme: " << e.what() << std::endl;
                                }
                                break;

                            case 2: // Listar Filmes
                                try {
                                    auto listaFilmes = cinema.obterGerenciadorFilmes()->listarTodosFilmes();

                                    if (listaFilmes.empty()) {
                                        std::cout << "Nenhum filme cadastrado. Volte ao menu principal e cadastre um filme." << std::endl;
                                    } else {
                                        std::cout << "-----Lista de Filmes ----" << std::endl;
                                        for (const auto& filme : listaFilmes) {
                                            std::cout << "Título: " << filme->getTitulo() << ", Duração: " << filme->getDuracao() << " minutos" << std::endl;
                                        }
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao listar filmes: " << e.what() << std::endl;
                                }
                                break;

                            case 3: // Remover Filme
                               try {
                                    std::string _titulo;
                                    std::cout << "Informe o título do filme a ser removido: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, _titulo);

                                    auto gerenciadorFilmes = cinema.obterGerenciadorFilmes();
                                    auto listaFilmes = gerenciadorFilmes->listarTodosFilmes();
                                    
                                    if(!listaFilmes.empty()) {
                                    bool filmeEncontrado = false;
                                    std::list<std::shared_ptr<Filme>>::iterator it = listaFilmes.begin(); 

                                    for (; it != listaFilmes.end(); ++it) {
                                        if ((*it)->getTitulo() == _titulo) {
                                            gerenciadorFilmes->removerFilme(*it);
                                            std::cout << "Filme removido com sucesso!" << std::endl;
                                            filmeEncontrado = true;
                                            break;
                                        }
                                    }
                                    if (!filmeEncontrado) {
                                        std::cout << "Filme com título " << _titulo << " não encontrado." << std::endl;
                                    }
                                }

                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao remover filme: " << e.what() << std::endl;
                                }
                                break;

                            case 4:
                                std::cout << "Voltando ao Menu Principal." << std::endl;
                                sairSubMenuFilme = true;
                                break;

                            default:
                                std::cout << "Opção inválida." << std::endl;
                                break;
                        }
                    }
                    break;
                case 3:
                    int opcaoSessao;
                    bool sairSubMenuSessao = false;
                    while (!sairSubMenuSessao) {
                        std::cout << "\n=== Menu Sessão ===\n";
                        std::cout << "1. Criar Nova Sessão\n";
                        std::cout << "2. Listar Sessões\n";
                        std::cout << "3. Remover Sessão\n";
                        std::cout << "4. Voltar ao Menu Principal\n";
                        std::cout << "Escolha a opção: ";
                        std::cin >> opcaoSessao;

                        switch (opcaoSessao) {
                            case 1: // Criar Nova Sessão
                              try {
                                    unsigned int _numeroSala;
                                    std::cout << "Informe o número da sala para a nova sessão: ";
                                    std::cin >> _numeroSala;

                                    auto gerenciadorSalas = cinema.obterGerenciadorSalas();
                                    auto listaSalas = gerenciadorSalas->listarTodasSalas();
                                    //verifica se a lista de salas esta vazia
                                    if (listaSalas.empty()) {
                                        throw std::runtime_error("Nenhuma sala cadastrada. Impossível criar nova sessão.");
                                    }

                                    std::shared_ptr<Sala> salaEncontrada = nullptr;
                                    //percorrer lista da sala para obter a sala. 
                                    for (const auto& sala : listaSalas) {
                                        if (sala->getNumero() == _numeroSala) {
                                            salaEncontrada = sala;
                                            break;
                                        }
                                    }

                                   if (salaEncontrada != nullptr) {
                                         // Listar os filmes disponíveis
                                        auto listaFilmes = cinema.obterGerenciadorFilmes()->listarTodosFilmes();
                                        if (!listaFilmes.empty()) {
                                            // Exibir os filmes disponíveis   
                                            std::cout << "----- Lista de Filmes -------"<< std::endl;
                                            int escolhaFilme = 0;

                                            for (const auto& filme : listaFilmes) {
                                                std::cout << ++escolhaFilme << ". " << filme->getTitulo() << std::endl;
                                            }

                                            // Escolher um filme
                                            int escolhaFilme;
                                            std::cout << "Escolha o número do filme: ";
                                            std::cin >> escolhaFilme;
                                            
                                            std::shared_ptr<Filme> _filmeEscolhido = nullptr;

                                            // Verificar se a escolha está dentro do intervalo válido
                                            if (escolhaFilme >= 1 && escolhaFilme <= listaFilmes.size()) {
                                                // define iterator do tipo filme para caminhar na lista de filmes
                                                std::list<std::shared_ptr<Filme>>::iterator it = listaFilmes.begin(); 
                                                for (int i = 1; i < escolhaFilme; ++i) {
                                                    ++it;
                                                }
                                                _filmeEscolhido = *it;

                                                // Restante da entrada de dados para a nova sessão
                                                std::cout << "Informe o identificador para a nova sessão: ";
                                                unsigned int _identificador;
                                                std::cin >> _identificador;

                                                std::string _horario;
                                                std::cout << "Informe o horário da nova sessão: ";
                                                std::cin.ignore();
                                                std::getline(std::cin, _horario);

                                                unsigned int _ingressosDisponiveis;
                                                std::cout << "Informe a quantidade de ingressos disponíveis: ";
                                                std::cin >> _ingressosDisponiveis;

                                                // Criar a nova sessão a partir dos dados de entrada
                                                std::shared_ptr<Sessao> _novaSessao = std::make_shared<Sessao>(salaEncontrada, _filmeEscolhido, _horario, _ingressosDisponiveis, _identificador);

                                                // Adicionar a nova sessão ao gerenciador de sessões
                                                cinema.obterGerenciadorSessao()->cadastrarSessao(_novaSessao);

                                                std::cout << "Nova sessão criada com sucesso!" << std::endl;
                                            } else {
                                                std::cout << "Escolha inválida de filme." << std::endl;
                                            }
                                        } else {
                                            std::cout << "Não há filmes cadastrados. Cadastre um filme antes de criar uma sessão." << std::endl;
                                        }
                                    } else {
                                        std::cout << "Sala com número " << _numeroSala << " não encontrada." << std::endl;
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao criar nova sessão: " << e.what() << std::endl;
                                }
                                break;
                            case 2: // Listar Sessões
                               try {
                                    auto gerenciadorSessao = cinema.obterGerenciadorSessao();
                                    if (!gerenciadorSessao) {
                                        throw std::runtime_error("Gerenciador de sessão não inicializado.");
                                    }
                                    //Definindo uma lista de sessão a partir do gerenciador
                                    std::list<std::shared_ptr<Sessao>> listaSessoes = gerenciadorSessao->listarTodasSessoes();

                                    if (listaSessoes.empty()) {
                                        std::cout << "Nenhuma sessão cadastrada." << std::endl;
                                    } else {
                                        std::cout << "------- Lista de Sessões --------" << std::endl;
                                        for (const std::shared_ptr<Sessao> sessao : listaSessoes) {
                                            // Utilizando a sobrecarga do operador de saída
                                            std::cout << sessao << std::endl;
                                        }
                                    }
                                } catch (const std::exception& e) {
                                    std::cerr << "Erro ao listar sessões: " << e.what() << std::endl;
                                } catch (...) {
                                    std::cerr << "Erro desconhecido ao listar sessões." << std::endl;
                                }
                                break;

                            case 3: // Remover Sessão
                                try {
                                    auto gerenciadorSessao = cinema.obterGerenciadorSessao();
                                    auto listaSessoes = gerenciadorSessao->listarTodasSessoes();

                                    if (listaSessoes.empty()) {
                                        std::cout << "Nenhuma sessão cadastrada." << std::endl;
                                    } else {
                                        unsigned int _identificadorSessao;
                                        std::cout << "Informe o identificador da sessão a ser removida: ";
                                        std::cin >> _identificadorSessao;

                                        cinema.obterGerenciadorSessao()->removerSessao(_identificadorSessao);
                                        std::cout << "Sessão removida com sucesso!" << std::endl;
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao remover sessão: " << e.what() << std::endl;
                                }

                            case 4: // Voltar ao Menu Principal
                                std::cout << "Voltando ao Menu Principal." << std::endl;
                                sairSubMenuSessao = true;
                                break;

                            default:
                                std::cout << "Opção inválida." << std::endl;
                                break;
                        }
                    }
                    break;
                case 4:
                     int opcaoClientes;
                    bool sairSubMenuClientes = false;

                    while (!sairSubMenuClientes) {
                        std::cout << "------- Menu Clientes --------" << std::endl;
                        std::cout << "1. Cadastrar Cliente"<< std::endl;
                        std::cout << "2. Listar Clientes"<< std::endl;
                        std::cout << "3. Remover Cliente"<< std::endl;
                        std::cout << "4. Comprar Ingresso"<< std::endl;
                        std::cout << "5. Voltar ao Menu Principal" << std::endl;
                        std::cout << "Escolha a opção: ";
                        std::cin >> opcaoClientes;

                        switch (opcaoClientes) {
                            case 1: // Cadastrar Cliente
                                try {
                                    std::string _nome;
                                    unsigned short int _idade;
                                    uint64_t _cpf;

                                    // Entrada de dados
                                    std::cout << "Informe o nome do cliente: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, _nome);
                                    std::cout << "Informe a idade do cliente: ";
                                    std::cin >> _idade;
                                    std::cout << "Informe o CPF do cliente: ";
                                    std::cin >> _cpf;

                                    std::shared_ptr<Cliente> novoCliente = std::make_shared<Cliente>(_nome, _idade, _cpf);
                                    cinema.obterGerenciadorClientes()->cadastrarCliente(novoCliente);

                                    std::cout << "Cliente cadastrado com sucesso!" << std::endl;
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao cadastrar cliente: " << e.what() << std::endl;
                                }
                                break;

                            case 2: // Listar Clientes
                                try {
                                    auto listaClientes = cinema.obterGerenciadorClientes()->listarTodosClientes();

                                    if (listaClientes.empty()) {
                                        std::cout << "Nenhum cliente cadastrado." << std::endl;
                                    } else {
                                        std::cout << "\n=== Lista de Clientes ===\n";
                                        for (const std::shared_ptr<Cliente>& cliente : listaClientes) {
                                            std::cout << cliente << std::endl;
                                        }
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao listar clientes: " << e.what() << std::endl;
                                }
                                break;

                            case 3: // Remover Cliente
                                try {
                                    auto gerenciadorClientes = cinema.obterGerenciadorClientes();
                                    std::list<std::shared_ptr<Cliente>> listaClientes = gerenciadorClientes->listarTodosClientes();

                                    if (listaClientes.empty()) {
                                        std::cout << "Nenhum cliente cadastrado para remoção." << std::endl;
                                    } else {
                                       // Exibir lista de clientes para que o usuário escolha qual remover
                                        std::cout << "-------------- Lista de Clientes ---------------";
                                        for(const std::shared_ptr<Cliente> cliente : listaClientes) {
                                            // Utilizando a sobrecarga do operador de saída
                                            std::cout << cliente << std::endl;
                                        }
                                        // Entrada de dados
                                        unsigned int _escolhaCliente;
                                        std::cout << "Escolha o cliente a ser removido (informe o número): ";
                                        std::cin >> _escolhaCliente;

                                        // Verificar se a escolha está dentro dos limites da lista usando loop e iterator
                                        auto it = listaClientes.begin();
                                        unsigned int contador = 1;
                                        while (it != listaClientes.end() && contador < _escolhaCliente) {
                                            ++it;
                                            ++contador;
                                        }

                                        if (it != listaClientes.end()) {
                                            gerenciadorClientes->removerCliente(*it);
                                            std::cout << "Cliente removido com sucesso!" << std::endl;
                                        } else {
                                            std::cout << "Escolha inválida." << std::endl;
                                        }
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao remover cliente: " << e.what() << std::endl;
                                }
                                break;
                            case 4:
                                try {
                                    auto gerenciadorClientes = cinema.obterGerenciadorClientes();
                                    auto gerenciadorSessoes = cinema.obterGerenciadorSessao();
                                    //Lista de clientes retornada do gerenciador
                                    std::list<std::shared_ptr<Cliente>> listaClientes = gerenciadorClientes->listarTodosClientes();
                                    //verifica se ha conteudo na lista de clientes -> cliente
                                    if (listaClientes.empty()) {
                                        std::cout << "Nenhum cliente cadastrado para comprar ingressos." << std::endl;
                                    } else {
                                        // Exibir lista de clientes para que o usuário escolha qual realizar a compra de ingresso
                                        std::cout << "-------------- Lista de Clientes ---------------";
                                        unsigned int i = 1;

                                        for (const std::shared_ptr<Cliente> cliente : listaClientes) {
                                            // Utilizando a sobrecarga do operador de saída
                                            std::cout << i << ". " << cliente << std::endl;
                                        }

                                        // Entrada de dados
                                        unsigned int _escolhaCliente;
                                        std::cout << "Escolha o cliente para comprar ingresso (informe o número): ";
                                        std::cin >> _escolhaCliente;

                                        // Verificar se a escolha está dentro dos limites da lista usando loop e iterator
                                        auto itCliente = listaClientes.begin();
                                        unsigned int contadorCliente = 1;

                                        while (itCliente != listaClientes.end() && contadorCliente < _escolhaCliente) {
                                            ++itCliente;
                                            ++contadorCliente;
                                        }

                                        if (itCliente != listaClientes.end()) {
                                            try {
                                                auto gerenciadorSessoes = cinema.obterGerenciadorSessao();
                                                // Exibir lista de sessões para que o usuário escolha qual comprar ingresso
                                                std::cout << "-------------- Lista de Sessões ---------------";
                                                std::list<std::shared_ptr<Sessao>> listaSessoes = gerenciadorSessoes->listarTodasSessoes();
                                                unsigned int j = 1;

                                                for (const std::shared_ptr<Sessao> sessao : listaSessoes) {
                                                    std::cout << j << ". " << sessao << std::endl;
                                                    ++j;
                                                }

                                                // Entrada de dados
                                                unsigned int _escolhaSessao;
                                                std::cout << "Escolha a sessão para comprar ingresso (informe o número): ";
                                                std::cin >> _escolhaSessao;

                                                // Verificar se a escolha está dentro dos limites da lista usando loop e iterator
                                                auto itSessao = listaSessoes.begin();
                                                unsigned int contadorSessao = 1;

                                                while (itSessao != listaSessoes.end() && contadorSessao < _escolhaSessao) {
                                                    ++itSessao;
                                                    ++contadorSessao;
                                                }

                                                if (itSessao != listaSessoes.end()) {
                                                    // Cadastro de dados para criar o ingresso
                                                    EnumTipoIngresso tipoIngresso;
                                                    // Obtenha outros dados conforme necessário
                                                    // Escolha do tipo de ingresso
                                                    std::cout << "Escolha o tipo de ingresso:\n";
                                                    std::cout << "1. Inteira\n";
                                                    std::cout << "2. Meia\n";
                                                    unsigned int _escolhaTipoIngresso;
                                                    std::cin >> _escolhaTipoIngresso;

                                                    switch (_escolhaTipoIngresso) {
                                                        case 1:
                                                            tipoIngresso = EnumTipoIngresso::INTEIRO;
                                                            break;
                                                        case 2:
                                                            tipoIngresso = EnumTipoIngresso::MEIO;
                                                            break;
                                                        default:
                                                            std::cout << "Escolha inválida para tipo de ingresso. Usando inteira por padrão.\n";
                                                            tipoIngresso = EnumTipoIngresso::INTEIRO;
                                                            break;
                                                    }
                                                    // Criar o ingresso
                                                    std::shared_ptr<Ingresso> ingresso = std::make_shared<Ingresso>(*itSessao, *itCliente, tipoIngresso);

                                                    // Realizar a compra de ingresso chamando o método comprarIngresso do cliente
                                                    (*itCliente)->comprarIngresso(*itSessao, ingresso);
                                                    std::cout << "Ingresso comprado com sucesso!" << std::endl;
                                                } else {
                                                    std::cout << "Escolha inválida para sessão." << std::endl;
                                                }
                                            } catch (std::exception& e) {
                                                std::cerr << "Erro ao comprar ingresso: " << e.what() << std::endl;
                                            }
                                        } else {
                                            std::cout << "Escolha inválida para cliente." << std::endl;
                                        }
                                    }
                                } catch (std::exception& e) {
                                    std::cerr << "Erro ao comprar ingresso: " << e.what() << std::endl;
                                }
                                break;  
                            case 5: // Voltar ao Menu Principal
                                std::cout << "Voltando ao Menu Principal." << std::endl;
                                sairSubMenuClientes = true;
                                break;

                            default:
                                std::cout << "Opção inválida." << std::endl;
                                break;
                        }
                    }
                    break;
                
                default:
                    std::cout << "Opção inválida. Tente novamente." << std::endl;
                    break;
            }
        } while (escolha != 5);
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
    return 0;
}