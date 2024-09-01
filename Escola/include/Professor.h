#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    private:
    float salario;
    string disciplina;

public:
    // Construtores
    Professor();
    Professor(string nome, string cpf, Endereco endereco, float salario, string disciplina);

    // Sobrescrita do m�todo exibirDetalhes
    void exibirDetalhes() const ;

    // Getters e Setters
    float getSalario() const;
    void setSalario(float salario);

    string getDisciplina() const;
    void setDisciplina(string disciplina);
};

#endif // PROFESSOR_H
