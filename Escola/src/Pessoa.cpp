#include "Pessoa.h"

Pessoa::Pessoa(){}

Pessoa::Pessoa(string nome, string cpf, Endereco endereco)
        :nome(nome), cpf(cpf), endereco(endereco) {}

// M�todos virtuais
void Pessoa::exibirDetalhes() const{
    cout << "Nome: " << nome << "\nCPF: " << cpf << "\nEndere�o: ";
    endereco.exibirEndereco();
    cout << endl;}

// Getters e Setters
string Pessoa::getNome() const{
    return nome;}
void Pessoa::setNome(string nome){
    this->nome = nome;}

string Pessoa::getCpf() const{
    return cpf;}
void Pessoa::setCpf(string cpf){
    this->cpf = cpf;}

Endereco Pessoa::getEndereco() const{
    return endereco;}
void Pessoa::setEndereco(Endereco endereco){
    this->endereco = endereco;}



Pessoa:: ~Pessoa(){}
