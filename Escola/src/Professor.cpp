#include "Professor.h"

// Construtores
Professor::Professor() {}
Professor::Professor(string nome, string cpf, Endereco endereco, float salario, string disciplina)
        : Pessoa(nome, cpf, endereco), salario(salario), disciplina(disciplina) {}

// Sobrescrita do m�todo exibirDetalhes
void Professor::exibirDetalhes() const{
    Pessoa::exibirDetalhes();
        cout << "Salario: R$ " << salario << "\nDisciplina: " << disciplina << endl;}

// Getters e Setters
float Professor::getSalario() const {
    return salario; }
void Professor::setSalario(float salario){
    this->salario = salario; }

string Professor::getDisciplina() const{
    return disciplina; }
void Professor::setDisciplina(string disciplina){
    this->disciplina = disciplina; }
