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

    // Método de pesquisa que retorna o índice ou -1 se não encontrado
    int pesquisarPessoa(string nome) const;

public:
    // Construtor
    SistemaGerenciador() {}

    // Método para inserir uma pessoa
    void inserirPessoa(Pessoa* pessoa);
    // Método para listar todas as pessoas
    void listarPessoas() const;

    // Método para exibir uma pessoa específica
    void exibirPessoa(string nome) const;

    // Método para alterar os dados de uma pessoa
    void alterarPessoa(string nome);

    // Método para remover uma pessoa
    void removerPessoa(string nome);

    // Método para gerar relatórios
    void gerarRelatorio() const;

    // Método para salvar dados em arquivo
    void salvarDados() const;

    // Método para carregar dados de arquivo
    void carregarDados();

    // Destrutor para liberar memória alocada
    ~SistemaGerenciador();
};

#endif // SISTEMAGERENCIADOR_H
