
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Ator {
public:
    Ator(const std::string& nome) : nome(nome) {}
    const std::string& getNome() const { return nome; }

private:
    std::string nome;
};