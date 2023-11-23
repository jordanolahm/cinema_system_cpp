# Sistema Controle de Cinema

## [Tecnologia : Projeto C++ seguindo padrão de projeto visto em sala.](https://prlalmeida.com.br/2021/10/29/cpp/)

### Lista de requisitos a serem vencidos

> Os **clientes do cinema** podem comprar ou não ingressos para assistir a **uma sessão**.

> Um cinema pode ter **muitas salas**, sendo necessário, portanto, registrar informações a respeito de cada sala, sua capacidade (numero de assentos disponíveis), numero de identificação.

> O cinema apresenta **muitos filmes**, de **vários gêneros**.  

> Um filme tem um **único gênero**, mas um **gênero pode se referir a muitos filmes**. O filme apresenta tambem informações como titulo e duração. Assim, sempre que um filme for ser apresentado, deve-se registrá-lo também.

> Cada filme deve apresentar **uma classificação Etária**: deve restringir a venda de ingressos para clientes que atendem aos requisitos de idade. 

> Um cliente classificado como pessoa deve conter idade, nome, gênero, cpf. Aqui cpf será tratado como um *uint64_t* importado de  **<cstdint>**.

> **Um filme** pode ter **muitos atores** atuando nele, e **um ator** pode atuar em **muitos filmes**. Em cada filme, **um ator** interpretará **um ou mais papéis diferentes**.Aqui a sugestão é usar um _enum de papeis_: coadjovante, protagonista, enredo. 

> Com base na **classificação de cada filme assistido**, deve ser rankeado na lista de exposição ou adicionado pontuação. Existe então uma função de classificar filme no menu opções sendo passado como dado: nome, _identificador_, nota. 

> **Um mesmo filme** pode ser apresentado em **diferentes salas e em horários diferentes**.

> A **Sessão** é apresentada em **uma sala e horário**.

> **Um filme sendo apresentado em uma sessão** tem um conjunto **máximo de ingressos**, determinado pela _capacidade da sala_, atributo membro da sala.

> O funcionário deve intermediar a **compra do ingresso**. Um ingresso deve conter informações como o tipo de ingresso _Enum_ **(meio ingresso ou ingresso inteiro)**. Além disso, um cliente só pode comprar ingressos para sessão ainda não encerradas.

> Sessões podem apresentar status: aberta, fechada, lotada. 


### Resumo estrutura de classes exemplo:

- Filmes: Representação de filmes com informações como título, duração, elenco, gênero, classificação.
- Sessões: Informações sobre as exibições dos filmes, incluindo filme, horário, sala, status e quantidade de ingressos .
- Salas: Detalhes sobre as salas de cinema, como capacidade, identificação, ingressos vendidos.
- Atores: Detalhes sobre os atores que participam dos filmes, nome, papel.
- Gêneros: Apresenta nome como atributo membro representando nome de gêneros. 
- Classificação: Apresenta idade mínima e descrição. 
- Cliente: idade, nome, gênero, cpf. 
- Ingresso: ingreso é a unidade de representação para entrada do cinema, contendo tipo e sessão relacionada. 

## Exemplificando as relações 

>Relação entre Cliente e Ingresso (Compra):
Cardinalidade: 1:N (Um cliente pode comprar vários ingressos, mas cada ingresso é comprado por apenas um cliente).

>Relação entre Sala e Sessao (Realiza Sessao):
Cardinalidade: 1:N (Uma sala pode realizar várias sessões, mas cada sessão é realizada em apenas uma sala).

>Relação entre Ator e Filme (Atua em):
Cardinalidade: M:N (Um ator pode atuar em vários filmes, e um filme pode ter vários atores).

>Relação entre Filme e Sessao (Exibido em):
Cardinalidade: 1:N (Um filme pode ser exibido em várias sessões, mas cada sessão exibe apenas um filme).

>Relação entre Sessao e Sala (Realizada em):
Cardinalidade: N:1 (Uma sessão é realizada em uma sala específica, mas uma sala pode ter várias sessões).

>Relação entre Sessao e Filme (Exibe):
Cardinalidade: N:1 (Uma sessão exibe um filme específico, mas um filme pode ser exibido em várias sessões).

>Relação entre Sessao e Ingresso (Vende):
Cardinalidade: 1:N (Uma sessão pode vender vários ingressos, mas cada ingresso é vendido para apenas uma sessão).

>Relação entre Cliente e Ingresso (Compra):
Cardinalidade: 1:N (Um cliente pode comprar vários ingressos, mas cada ingresso é comprado por apenas um cliente).


### Resumo das funções principais:
- **Gerenciadores de clientes, salas e filmes: apresentam a lista de cada contexto atualizado.**
- **Venda de Ingressos: Usuários podem comprar ingressos para sessões.**
- **Informações sobre Filmes: Detalhes sobre filmes, incluindo elenco, gênero e classificação.**
- **Impressão do ticket de reserva sessão.**

### Menu
> Deve apresentar um menu simples com as opções presentes no sistema, cadastro, visualização, impressão de ticket, visão da programação semanal. 

### Diagrama de classes e relacionamento de entidades
> Apresentar diagramação completa das classes relacionadas e fluxo de execução do sistema, utilizando a ferramenta starUML.

### Tratamento de Exceções
> Implementar tratamento de exceções para lidar com cenários como entradas inválidas do usuário, falhas de leitura/gravação, mensagens amigáveis para fluxo de informações no cinema. 

### Gravação de dados
> Implementar funcionalidades de leitura/gravação de dados em listas para persistir informações sobre filmes, sessões, salas.

##Diagrama de classe Definido

### Cinema: Classe principal, onde relaciona os gerenciadores trazendo para si, as informações gerais do cinema em termos de operação (salas, filmes, sessões).

>Atributos Privados:

>salas: std::list<std::shared_ptr<Sala>>
>filmes: std::list<std::shared_ptr<Filme>>
>sessoes: std::list<std::shared_ptr<Sessao>>
>gerenciadorFilmes: std::shared_ptr<GerenciadorFilmes>
>gerenciadorSalas: std::shared_ptr<GerenciadorSalas>
>gerenciadorClientes: std::shared_ptr<GerenciadorClientes>
>gerenciadorSessao: std::shared_ptr<GerenciadorSessao>

>Métodos Públicos:
>obterSalas(): std::list<std::shared_ptr<Sala>>
>obterFilmes(): std::list<std::shared_ptr<Filme>>
>obterSessoes(): std::list<std::shared_ptr<Sessao>>
>obterGerenciadorSalas(): std::shared_ptr<GerenciadorSalas>
>obterGerenciadorFilmes(): std::shared_ptr<GerenciadorFilmes>
>obterGerenciadorClientes(): std::shared_ptr<GerenciadorClientes>
>obterGerenciadorSessao(): std::shared_ptr<GerenciadorSessao>


### GerenciadorFilmes: Classe responsável por gerenciar o filme de acordo com a lista de filmes existentes. 

>Atributos Privados:
>sessoes: std::list<std::shared_ptr<Filme>>

>Métodos Públicos:
>cadastrarFilme(const std::shared_ptr<Filme>&): void
>listarTodosFilmes(): std::list<std::shared_ptr<Filme>>
>removerFilme(const std::shared_ptr<Filme>&): void

### Filme: Classe responsável por relacionar um elenco de atores na sua estrutura. No sistema relaciona sessão e sala.  
>Atributos Privados:

>titulo: std::string
>duracao: string
>genero: std::string
>classificacaoEtaria: int
>atores: std::vector<std::shared_ptr<Ator>>

>Métodos Públicos:
>getTitulo(): std::string
>getDuracao(): int
>getGenero(): std::string
>getClassificacaoEtaria(): int
>getAtores(): std::vector<std::shared_ptr<Ator>>
>setTitulo(const std::string&): void
>setDuracao(int): void
>setGenero(const std::string&): void
>setClassificacaoEtaria(int): void


### Ator: Classe genérica que representa ator ou atriz de um filme. 

>Atributos Privados:
>nome: std::string
>papel: std:: string

>Métodos Públicos:
>getNome(): std::string
>setNome(const std::string&): void
>getPapel(): std::string
>setPapel(const std::string&): void


### Genero: Classe genérica que representa genero de um determinado filme. 

>Atributos Privados:
>nome: std::string

>Métodos Públicos:
>getNome(): std::string
>setNome(const std::string&): void


### Classificação: Classe genérica que representa classificação etaria de um filme. 

>Atributos Privados:
>descricao: std::string
>idadeMinima: std::unsigned int

>Métodos Públicos:
>getDescricao(): std::string
>setDescricao(const std::string&): void
>getIdadeMinima(): unsigned int
>setIdadeMinima(idadeMinima:unsigned int): void


### GerenciadorSalas: classe que gerencia as salas do cinema, efetuar ações com o objeto de Sala. 

>Atributos Privados:
>salas: std::list<std::shared_ptr<Sala>>

>Métodos Públicos:
>cadastrarSala(const std::shared_ptr<Sala>&): void
>listarTodasSalas(): std::list<std::shared_ptr<Sala>>
>removerSala(const std::shared_ptr<Sala>&): void


### Sala: classe responsável por construir as características de uma sala de cinema com identificação e capacidade. 

>Atributos Privados:
>numero: unsigned int
>capacidade: unsigned short int

>Métodos Públicos:
>getNumero(): unsigned int
>getCapacidade(): unsigned short int


### GerenciadorSessao: classe que gerencia Sessao, utilizada para efetuar ações com o objeto de Sessao. 

>Atributos Privados:
>sessoes: std::list<std::shared_ptr<Sessao>>

>Métodos Públicos:
>cadastrarSessao(const std::shared_ptr<Sessao>&): void
>listarTodasSessoes(): std::list<std::shared_ptr<Sessao>>
>removerSessao(const std::shared_ptr<Sessao>&): void

### Sessao: Classe que possuir as informações de uma sessão de cinema. Quando existir, apresenta um filme e está numa sala. Apresenta quantidade limitada de ingressos, quando limitada, deve estar lotada. Sempre aberta quando construída. 

>Atributos Privados:
>sala: std::shared_ptr<Sala>
>filme: std::shared_ptr<Filme>
>horario: std::string
>ingressosDisponiveis: int
>status: StatusSessao

>Métodos Públicos:
>getHorario(): std::string
>getStatus(): StatusSessao
>abrirSessao(): void
>fecharSessao(): void
>lotarSessao(): void
>classificarFilme(const std::shared_ptr<Filme>&, int): void

>StatusSessao (Enum): Representa o status da sessao.
Aberta, Fechada ou Lotada

### GerenciadorClientes: Classes que gerencia os objetos da classe sessão, utilizada para efetuar operações. 

>Atributos Privados:
>clientes: std::list<std::shared_ptr<Cliente>>

>Métodos Públicos:
>cadastrarCliente(const std::shared_ptr<Cliente>&): void
>listarTodosClientes(): std::list<std::shared_ptr<Cliente>>
>removerCliente(const std::shared_ptr<Cliente>&): void


### Cliente: classe responsavel por construir a estrutura do cliente. Cliente deve possuir caracteristicas de uma pessoa, pode possuir um ou mais ingressos.

>Atributos Privados:
>nome: std::string
>idade: int
>genero: std::string
>cpf: uint64_t
>std::list<std::shared_ptr<Ingresso>>

>Métodos Públicos:
>comprarIngresso(const std::shared_ptr<Sessao>&, TipoIngresso): std::list<std::shared_ptr<Ingresso>>
>listarIngressos(): std::list<std::shared_ptr<Ingresso>>


### Ingresso: classe responsável por construir as informacoes de um ingresso. 

>Atributos Privados:
>tipo: TipoIngresso
>sessao: std::shared_ptr<Sessao>

>Métodos publicos: 
>getTipo(): TipoIngresso
>getSessao(): Sessao

>TipoIngresso (Enum): Representa o tipo do ingresso.
Inteiro
Meia

### Diagrama de Entidade e Relacionamento (DER): Responsável por relacionar os objetos de acordo com ações ou responsabilidades entre os dados de classes 

>Cliente
Relacionamento: Compra (1:N com Ingresso)

>Sala
Relacionamento: Realiza Sessao (1:N com Sessao)

>Filme
Relacionamento: Possui Genero (M:N com Genero)
Relacionamento: Atua em (M:N com Ator)
Relacionamento: Exibido em (1:N com Sessao)

>Ator
Relacionamento: Atua em (M:N com Filme)

>Genero
Relacionamento: Possui Genero (M:N com Filme)

>Sessao
Relacionamento: Realizada em (N:1 com Sala)
Relacionamento: Exibe (N:1 com Filme)
Relacionamento: Vende (1:N com Ingresso)

>Ingresso
Relacionamento: Compra (N:1 com Cliente, N:1 com Sessao)

>GerenciadorFilmes
Relacionamento: Gerencia (1:1 com Filme)

>GerenciadorSalas
Relacionamento: Gerencia (1:1 com Sala)

>GerenciadorClientes
Relacionamento: Gerencia (1:1 com Cliente)

>GerenciadorSessao
Relacionamento: Gerencia (1:1 com Sessao)

>Classificacao
Relacionamento: Classifica (1:N com Filme)


## Relacionamentos diretos entre os objetos:

Compra (1:N entre Cliente e Ingresso)
Realiza Sessao (1:N entre Sala e Sessao)
Atua em (M:N entre Ator e Filme)
Exibido em (1:N entre Filme e Sessao)
Realizada em (N:1 entre Sessao e Sala)
Exibe (N:1 entre Sessao e Filme)
Vende (1:N entre Sessao e Ingresso)
Possui Genero (M:N entre Filme e Genero)
Gerencia (1:1 entre Gerenciador e respectiva entidade)
Classifica (1:N entre Classificacao e Filme)
