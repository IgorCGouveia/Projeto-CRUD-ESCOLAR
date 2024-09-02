#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

class Aluno : public Pessoa
{
    private:
    string matricula;
    string curso;

public:
    // Construtores
    Aluno();
    Aluno(string nome, string cpf, Endereco endereco, string matricula, string curso);

    // Sobrescrita do m�todo exibirDetalhes
    void exibirDetalhes() const override;

    // Getters e Setters
    string getMatricula() const;
    void setMatricula(string matricula);

    string getCurso() const;
    void setCurso(string curso);
};

#endif // ALUNO_H
