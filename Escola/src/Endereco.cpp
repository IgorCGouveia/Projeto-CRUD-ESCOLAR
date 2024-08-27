#include "Endereco.h"

//Construtores
Endereco::Endereco(){}

Endereco::Endereco(string rua, string cidade, string estado, string cep)
        : rua(rua), cidade(cidade), estado(estado), cep(cep) {}

//Getters e Setters
string Endereco::getRua(){
    return rua;}

void Endereco::setRua(string rua){
    this->rua = rua;}

string Endereco::getCidade(){
    return cidade;}

void Endereco::setCidade(string cidade){
    this->cidade = cidade;}

string Endereco::getEstado(){
    return estado;}

void Endereco::setEstado(string estado){
    this->estado = estado;}

string Endereco::getCep(){
    return cep;}

void Endereco::setCep(string cep){
    this->cep = cep;}

//Exibir endereço
void Endereco::exibirEndereco() const{
    cout << "Rua: " << rua << ", Cidade: " << cidade << ", Estado: " << estado << ", CEP: " << cep;}
