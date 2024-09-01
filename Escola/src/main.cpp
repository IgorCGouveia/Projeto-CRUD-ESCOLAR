#include <iostream>
#include <memory>
#include "Aluno.h"
#include "SistemaGerenciador.h"
#include "Pessoa.h"
#include "Professor.h"
using namespace std;

int main() {
SistemaGerenciador sistema;
sistema.carregarDados(); // Carregar dados ao iniciar o programa
int opcao;

do {
    cout << "\n===== Menu Principal =====\n";
    cout << "1. Inserir Pessoa\n";
    cout << "2. Listar Todas as Pessoas\n";
    cout << "3. Exibir Detalhes de uma Pessoa\n";
    cout << "4. Alterar Dados de uma Pessoa\n";
    cout << "5. Remover uma Pessoa\n";
    cout << "6. Gerar Relatorio\n";
    cout << "7. Sair\n";
    cout << "Escolha uma opcaoo: ";
    cin >> opcao;
    cin.ignore(); // Limpar o buffer de entrada

    switch (opcao) {
        case 1: { // Inserir Pessoa
            int tipo;
            cout << "Deseja inserir um Aluno (1) ou um Professor (2)? ";
            cin >> tipo;
            cin.ignore();

            if (tipo == 1) { // Inserir Aluno
                string nome, cpf, rua, cidade, estado, cep, curso;
                int matricula;
                cout << "Digite o nome do aluno: "; getline(cin, nome);
                cout << "Digite o CPF do aluno: "; getline(cin, cpf);
                cout << "Digite o endere�o do aluno:\n";
                cout << "  Rua: "; getline(cin, rua);
                cout << "  Cidade: "; getline(cin, cidade);
                cout << "  Estado: "; getline(cin, estado);
                cout << "  CEP: "; getline(cin, cep);
                cout << "Digite a matricula do aluno: "; cin >> matricula; cin.ignore();
                cout << "Digite o curso do aluno: "; getline(cin, curso);

                Endereco endereco(rua, cidade, estado, cep);
                Pessoa* aluno = new Aluno(nome, cpf, endereco, matricula, curso);
                sistema.inserirPessoa(aluno);
                cout << "Aluno inserido com sucesso!\n";
            }
            else if (tipo == 2) { // Inserir Professor
                string nome, cpf, rua, cidade, estado, cep, disciplina;
                float salario;
                cout << "Digite o nome do professor: "; getline(cin, nome);
                cout << "Digite o CPF do professor: "; getline(cin, cpf);
                cout << "Digite o endereco do professor:\n";
                cout << "  Rua: "; getline(cin, rua);
                cout << "  Cidade: "; getline(cin, cidade);
                cout << "  Estado: "; getline(cin, estado);
                cout << "  CEP: "; getline(cin, cep);
                cout << "Digite o sal�rio do professor: "; cin >> salario; cin.ignore();
                cout << "Digite a disciplina do professor: "; getline(cin, disciplina);

                Endereco endereco(rua, cidade, estado, cep);
                Pessoa* prof = new Professor(nome, cpf, endereco, salario, disciplina);
                sistema.inserirPessoa(prof);
                cout << "Professor inserido com sucesso!\n";
            }
            else {
                cout << "Opcao invalida!\n";
            }
            break;
        }
        case 2: { // Listar Todas as Pessoas
            sistema.listarPessoas();
            break;
        }
        case 3: { // Exibir Detalhes de uma Pessoa
            string nome;
            cout << "Digite o nome da pessoa: "; getline(cin, nome);
            sistema.exibirPessoa(nome);
            break;
        }
        case 4: { // Alterar Dados de uma Pessoa
            string nome;
            cout << "Digite o nome da pessoa a ser alterada: "; getline(cin, nome);
            sistema.alterarPessoa(nome);
            break;
        }
        case 5: { // Remover uma Pessoa
            string nome;
            cout << "Digite o nome da pessoa a ser removida: "; getline(cin, nome);
            sistema.removerPessoa(nome);
            break;
        }
        case 6: { // Gerar Relat�rio
            sistema.gerarRelatorio();
            break;
        }
        case 7: { // Sair
            cout << "Salvando dados e saindo do sistema...\n";
            sistema.salvarDados();
            break;
        }
        default:
            cout << "Opcao invalida! Por favor, tente novamente.\n";
    }

} while (opcao != 7);

return 0;
}
