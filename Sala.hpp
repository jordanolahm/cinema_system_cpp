class Sala {
public:
    Sala(int numero, int capacidade);
    int getNumero() const { return numero; }
    int getCapacidade() const { return capacidade; }

private:
    int numero;
    int capacidade;
};