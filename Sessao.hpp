class Sessao {
public:
    Sessao(Filme* filme, Sala* sala, const std::string& horario, int capacidade);
    const Filme* getFilme() const { return filme; }
    const Sala* getSala() const { return sala; }
    const std::string& getHorario() const { return horario; }
    int getCapacidade() const { return capacidade; }
    int getIngressosVendidos() const { return ingressosVendidos; }
    bool sessaoEncerrada() const { return ingressosVendidos >= capacidade; }
    bool venderIngresso(bool meioIngresso);

private:
    Filme* filme;
    Sala* sala;
    std::string horario;
    int capacidade;
    int ingressosVendidos;
};
