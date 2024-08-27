#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Pessoa
{
    protected:
        string nome;
        string cpf;
        Endereco endereco;

    public:
        // Construtores
        Pessoa() {}
        Pessoa(string nome, string cpf, Endereco endereco);

        // Métodos virtuais
        virtual void exibirDetalhes() const;

        // Getters e Setters
        string getNome() const;
        void setNome(string nome);

        string getCpf() const;
        void setCpf(string cpf);

        Endereco getEndereco() const;
        void setEndereco(Endereco endereco);

        // Destrutor virtual
        virtual ~Pessoa();
};

#endif // PESSOA_H
