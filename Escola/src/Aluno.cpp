#include "Aluno.h"


Aluno::Aluno(string nome, string cpf, Endereco endereco, string matricula, string curso)
    : Pessoa(nome, cpf, endereco), matricula(matricula), curso(curso) {}

// Definicao do metodo sobrescrito
void Aluno::exibirDetalhes() const {
    Pessoa::exibirDetalhes();
    cout << "Matricula: " << matricula << "\nCurso: " << curso << endl;
}

// Getters e Setters
string Aluno::getMatricula() const {
    return matricula;
}
void Aluno::setMatricula(string matricula) {
    this->matricula = matricula;
}

string Aluno::getCurso() const {
    return curso;
}
void Aluno::setCurso(string curso) {
    this->curso = curso;
}
