#ifndef ALUNO_H
#define ALUNO_H

#include <Pessoa.h>

class Aluno : public Pessoa
{
    private:
    int matricula;
    string curso;

public:
    // Construtores
    Aluno() {};
    Aluno(string nome, string cpf, Endereco endereco, int matricula, string curso);

    // Sobrescrita do método exibirDetalhes
    void exibirDetalhes() const override;

    // Getters e Setters
    int getMatricula() const;
    void setMatricula(int matricula);

    string getCurso() const;
    void setCurso(string curso);
};

#endif // ALUNO_H
