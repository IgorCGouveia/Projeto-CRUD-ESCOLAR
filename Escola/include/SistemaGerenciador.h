#ifndef SISTEMAGERENCIADOR_H
#define SISTEMAGERENCIADOR_H
#include "Pessoa.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> // Para transform
using namespace std;

class SistemaGerenciador
{
private:
    vector<Pessoa*> pessoas; // Vetor com polimorfismo

    // M�todo de pesquisa que retorna o �ndice ou -1 se n�o encontrado
    int pesquisarPessoa(string nome) const;

public:
    // Construtor
    SistemaGerenciador();

    // M�todo para inserir uma pessoa
    void inserirPessoa(Pessoa* pessoa);
    // M�todo para listar todas as pessoas
    void listarPessoas() const;

    // M�todo para exibir uma pessoa espec�fica
    void exibirPessoa(string nome) const;

    // M�todo para alterar os dados de uma pessoa
    void alterarPessoa(string nome);

    // M�todo para remover uma pessoa
    void removerPessoa(string nome);

    // M�todo para gerar relat�rios
    void gerarRelatorio() const;

    // M�todo para salvar dados em arquivo
    void salvarDados() const;

    // M�todo para carregar dados de arquivo
    void carregarDados();

    // Destrutor para liberar mem�ria alocada
    ~SistemaGerenciador();
};

#endif // SISTEMAGERENCIADOR_H
