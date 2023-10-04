#ifndef ATOR_HPP
#define ATOR_HPP


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Ator {
public:

    Ator(const std::string& nome); 
    
    const std::string& getNome() const; 

private:
    std::string nome;
};

#endif // ATOR_HPP