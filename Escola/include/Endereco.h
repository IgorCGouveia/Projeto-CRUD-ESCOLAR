#ifndef ENDERECO_H
#define ENDERECO_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> // Para transform
using namespace std;


class Endereco
{
private:
    string rua;
    string cidade;
    string estado;
    string cep;
public:
    // Construtores
    Endereco();
    Endereco(string rua, string cidade, string estado, string cep);

    // Métodos Getters e Setters
    string getRua();
    void setRua(string rua);

    string getCidade();
    void setCidade(string cidade);

    string getEstado();
    void setEstado(string estado);

    string getCep();
    void setCep(string cep);

    // Método para exibir endereço
    void exibirEndereco() const;
};

#endif // ENDERECO_H
