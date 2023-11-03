# Sistema Controle de Cinema

## [Tecnologia : Projeto C++ seguindo padrão de projeto visto em sala.](https://prlalmeida.com.br/2021/10/29/cpp/)

### Lista de requisitos a serem vencidos

> Os **clientes do cinema** podem comprar ou não ingressos para assistir a **uma sessão**.

> Um cinema pode ter **muitas salas**, sendo necessário, portanto, registrar informações a respeito de cada sala, sua capacidade (numero de assentos disponíveis), numero de identificação.

> O cinema apresenta **muitos filmes**, de **vários gêneros**.  

> Um filme tem um **único gênero**, mas um **gênero pode se referir a muitos filmes**. O filme apresenta tambem informações como titulo e duração. Assim, sempre que um filme for ser apresentado, deve-se registrá-lo também.

> Cada filme deve apresentar **uma classificação Etária**: deve restringir a venda de ingressos para clientes que atendem aos requisitos de idade. 

> Um cliente do tipo pessoa: idade, nome, gênero, cpf. Aqui cpf será tratado como um *uint64_t* importado de  **<cstdint>**.

> **Um filme** pode ter **muitos atores** atuando nele, e **um ator** pode atuar em **muitos filmes**. Em cada filme, **um ator** interpretará **um ou mais papéis diferentes**. Por uma questão de propaganda, é útil anunciar os principais atores do filme e que papéis eles interpretam. Aqui a sugestão é usar um _enum de papeis_: coadjovante, protagonista, enredo. 

> Com base na **classificação de cada filme assistido**, deve ser rankeado na lista de exposição ou adicionado pontuação. Existe então uma função de classificar filme no menu opções sendo passado como dado: nome, _identificador_, nota. 

> **Um mesmo filme** pode ser apresentado em **diferentes salas e em horários diferentes**.

> A **Sessão** é apresentada em **uma sala e horário**.

> **Um filme sendo apresentado em uma sessão** tem um conjunto **máximo de ingressos**, determinado pela _capacidade da sala_, atributo membro da sala.

> O funcionário deve intermediar a **compra do ingresso**. Um ingresso deve conter informações como o tipo de ingresso _Enum_ **(meio ingresso ou ingresso inteiro)**. Além disso, um cliente só pode comprar ingressos para sessão ainda não encerradas.

> Sessões podem apresentar status: aberta, fechada, lotada. 

## Funcionalidades adicionais com probabilidade de desenvolvimento

> Reservas de Ingressos: Permitir que os clientes **façam reservas de ingressos** para uma sessão específica. Debitando do total de ingressos vendidos e anunciados no menu principal.

> Programação Semanal: Implementar uma visão semanal da programação do cinema, mostrando **todos os filmes e sessões para cada dia da semana**. Expor uma tabela como visto na bilheteria. 

> Cancelamento de Ingressos: Permita que os clientes **cancelem suas compras de ingressos** com antecedência, talvez sujeito a uma taxa de cancelamento, desconto na devolução.

> Relatórios de Desempenho: Implemente **relatórios detalhados de desempenho**, incluindo dados sobre vendas, ocupação das salas, filmes mais populares, etc. Concentrar um arquivo com dados de filmes, ingressos, dados de bilheteria...

> Programação por Diretor/Ator: Permitir que os usuários **visualizem** a programação com base no **diretor ou ator** de sua escolha, com base em seus favoritos. 

> Buscar sessões com base no gênero: Exibir quais **dias e horários** temos sessões especificamente de um **gênero**. Sugestão de filtro de filmes.  

> Histórico de Transações de um determinado cliente: Permitir acessar o **histórico de transações passadas**, incluindo filmes assistidos, reservas de um determinado cliente.

### Resumo estrutura de classes exemplo:

- Filmes: Representação de filmes com informações como título, diretor, elenco, gênero, classificação, descrição, tag.
- Sessões: Informações sobre as exibições dos filmes, incluindo data, horário, sala, status.
- Salas: Detalhes sobre as salas de cinema, como capacidade, identificação.
- Atores: Detalhes sobre os atores que participam dos filmes, nome, papel.
- Gêneros: Categorias de filmes, como ação, comédia, drama, etc.
- Classificação: Classificação indicativa dos filmes.
- Cliente: idade, nome, gênero, cpf, profissão. 

### Resumo das funções principais:

- **Agendamento de Sessões: Permite agendar sessões para exibição de filmes em salas específicas.**
- **Reserva de Ingressos: Usuários podem reservar ingressos para sessões futuras.**
- **Consulta de Programação: Visualização da programação atual e futura.**
- **Informações sobre Filmes: Detalhes sobre filmes, incluindo elenco, gênero, diretor, protagonistas.**
- **Relatórios Estatísticos: Estatísticas sobre a ocupação das salas, popularidade de gêneros, filmes mais assistidos.**
- **Impressão do ticket de reserva sessão.**

### Diagrama de classes e relacionamento de entidades
> Apresentar diagramação completa das classes relacionadas e fluxo de execução do sistema, utilizando a ferramenta drawio.

### Tratamento de Exceções
> Implementar tratamento de exceções para lidar com cenários como entradas inválidas do usuário, falhas de leitura/gravação, mensagens amigáveis para controle de faixa etária.

### Gravação de dados

> Implementar funcionalidades de leitura/gravação de dados em arquivos para persistir informações sobre filmes, sessões, lotação.

