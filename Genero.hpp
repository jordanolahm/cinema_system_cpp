class Genero {
public:
    Genero(const std::string& nome) : nome(nome) {}
    const std::string& getNome() const { return nome; }

private:
    std::string nome;
};