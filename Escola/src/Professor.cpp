#include "Professor.h"

// Construtores
Professor::Professor() {}
Professor::Professor(string nome, string cpf, Endereco endereco, float salario, string disciplina)
        : Pessoa(nome, cpf, endereco), salario(salario), disciplina(disciplina) {}

// Sobrescrita do método exibirDetalhes
void exibirDetalhes() const override{
Pessoa::exibirDetalhes();
    cout << "Salario: R$ " << salario << "\nDisciplina: " << disciplina << endl;}

// Getters e Setters
float getSalario() const {
    return salario; }
void setSalario(float salario){
    this->salario = salario; }

string getDisciplina() const{
    return disciplina; }
void setDisciplina(string disciplina){
    this->disciplina = disciplina; }
