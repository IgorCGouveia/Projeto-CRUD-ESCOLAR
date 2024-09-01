#include "Aluno.h"


Aluno::Aluno(string nome, string cpf, Endereco endereco, int matricula, string curso)
    : Pessoa(nome, cpf, endereco), matricula(matricula), curso(curso) {}

// Defini��o do m�todo sobrescrito
void Aluno::exibirDetalhes() const {
    Pessoa::exibirDetalhes();
    cout << "Matricula: " << matricula << "\nCurso: " << curso << endl;
}

// Getters e Setters
long int Aluno::getMatricula() const {
    return matricula;
}
void Aluno::setMatricula(int matricula) {
    this->matricula = matricula;
}

string Aluno::getCurso() const {
    return curso;
}
void Aluno::setCurso(string curso) {
    this->curso = curso;
}
