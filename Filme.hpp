#ifndef FILME_HPP
#define FILME_HPP


class Filme {
public:
    Filme(const std::string& titulo, int duracao, Genero* genero);
    const std::string& getTitulo() const { return titulo; }
    int getDuracao() const { return duracao; }
    const Genero* getGenero() const { return genero; }
    void adicionarAtor(Ator* ator, const std::string& papel);

private:
    std::string titulo;
    int duracao;
    Genero* genero;
    std::unordered_map<Ator*, std::string> elenco;
};

#endif // FILME_HPP