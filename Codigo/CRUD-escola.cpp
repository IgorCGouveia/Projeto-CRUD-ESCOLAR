#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//Endereco.h
class Endereco {
private:
    string rua;
    string cidade;
    string estado;
    string cep;
public:
    // Construtores
    Endereco() {}
    Endereco(string rua, string cidade, string estado, string cep)
        : rua(rua), cidade(cidade), estado(estado), cep(cep) {}
    
    // Métodos Get e Set
    string getRua() { return rua; }
    void setRua(string rua) { this->rua = rua; }

    string getCidade() { return cidade; }
    void setCidade(string cidade) { this->cidade = cidade; }

    string getEstado() { return estado; }
    void setEstado(string estado) { this->estado = estado; }

    string getCep() { return cep; }
    void setCep(string cep) { this->cep = cep; }

    // Método para exibir endereço
    void exibirEndereco() const {
        cout << "Rua: " << rua << ", Cidade: " << cidade << ", Estado: " << estado << ", CEP: " << cep;
    }
};

//Pessoa.h
class Pessoa {
protected:
    string nome;
    string cpf;
    Endereco endereco;

public:
    // Construtores
    Pessoa() {}
    Pessoa(string nome, string cpf, Endereco endereco)
        : nome(nome), cpf(cpf), endereco(endereco) {}
    
    // Métodos virtuais
    virtual void exibirDetalhes() const {
        cout << "Nome: " << nome << "\nCPF: " << cpf << "\nEndereço: ";
        endereco.exibirEndereco();
        cout << endl;
    }
    
    // Get e Set
    string getNome() const { return nome; }
    void setNome(string nome) { this->nome = nome; }

    string getCpf() const { return cpf; }
    void setCpf(string cpf) { this->cpf = cpf; }

    Endereco getEndereco() const { return endereco; }
    void setEndereco(Endereco endereco) { this->endereco = endereco; }

    // Destrutor virtual
    virtual ~Pessoa() {}
};

//Aluno.h
class Aluno : public Pessoa {
private:
    int matricula;
    string curso;

public:
    // Construtores
    Aluno() {}
    Aluno(string nome, string cpf, Endereco endereco, int matricula, string curso)
        : Pessoa(nome, cpf, endereco), matricula(matricula), curso(curso) {}
    
    // Sobrescrita de metodo
    void exibirDetalhes() const override {
        Pessoa::exibirDetalhes();
        cout << "Matrícula: " << matricula << "\nCurso: " << curso << endl;
    }

    // Get e Set
    int getMatricula() const { return matricula; }
    void setMatricula(int matricula) { this->matricula = matricula; }

    string getCurso() const { return curso; }
    void setCurso(string curso) { this->curso = curso; }
};

//Professor.h
class Professor : public Pessoa {
private:
    float salario;
    string disciplina;

public:
    // Construtores
    Professor() {}
    Professor(string nome, string cpf, Endereco endereco, float salario, string disciplina)
        : Pessoa(nome, cpf, endereco), salario(salario), disciplina(disciplina) {}
    
    // Sobrescrita de metodo
    void exibirDetalhes() const override {
        Pessoa::exibirDetalhes();
        cout << "Salário: R$ " << salario << "\nDisciplina: " << disciplina << endl;
    }

    // Get e Set
    float getSalario() const { return salario; }
    void setSalario(float salario) { this->salario = salario; }

    string getDisciplina() const { return disciplina; }
    void setDisciplina(string disciplina) { this->disciplina = disciplina; }
};

// Classe SistemaGerenciador
class SistemaGerenciador {
private:
    vector<Pessoa*> pessoas; // Vetor com polimorfismo

    // Método pra pesquisar e retornar o índice ou -1 se não encontrado
    int pesquisarPessoa(string nome) const {
        // Converte o nome para minúsculas para pesquisa case-insensitive
        string nomePesquisa = nome;
        transform(nomePesquisa.begin(), nomePesquisa.end(), nomePesquisa.begin(), ::tolower);

        for (size_t i = 0; i < pessoas.size(); ++i) {
            string nomeAtual = pessoas[i]->getNome();
            transform(nomeAtual.begin(), nomeAtual.end(), nomeAtual.begin(), ::tolower);
            if (nomeAtual == nomePesquisa) return i;
        }
        return -1; // nao encontrou
    }

public:
    // Construtor
    SistemaGerenciador() {}

    // Metodo para inserir uma pessoa
    void inserirPessoa(Pessoa* pessoa) {
        pessoas.push_back(pessoa);
    }

    // Método para listar todas as pessoas
    void listarPessoas() const {
        if (pessoas.empty()) {
            cout << "Nenhuma pessoa cadastrada.\n";
            return;
        }
        for (Pessoa* pessoa : pessoas) {
            pessoa->exibirDetalhes();
            cout << "-----------------------\n";
        }
    }

    // Metodo para exibir uma pessoa especifica
    void exibirPessoa(string nome) const {
        int indice = pesquisarPessoa(nome);
        if (indice != -1) {
            pessoas[indice]->exibirDetalhes();
        } else {
            cout << "Pessoa não encontrada!\n";
        }
    }

    // Metodo para alterar os dados de uma pessoa
    void alterarPessoa(string nome) {
        int indice = pesquisarPessoa(nome);
        if (indice != -1) {
            Pessoa* pessoa = pessoas[indice];
            string novoNome, novoCpf, novaRua, novaCidade, novoEstado, novoCep;

            cout << "Digite o novo nome: "; getline(cin, novoNome);
            cout << "Digite o novo CPF: "; getline(cin, novoCpf);
            cout << "Digite o novo endereço:\n";
            cout << "  Rua: "; getline(cin, novaRua);
            cout << "  Cidade: "; getline(cin, novaCidade);
            cout << "  Estado: "; getline(cin, novoEstado);
            cout << "  CEP: "; getline(cin, novoCep);

            pessoa->setNome(novoNome);
            pessoa->setCpf(novoCpf);
            Endereco novoEndereco(novaRua, novaCidade, novoEstado, novoCep);
            pessoa->setEndereco(novoEndereco);

            // Verificar se a pessoa é um Aluno ou Professor para alterar atributos específicos
            Aluno* aluno = dynamic_cast<Aluno*>(pessoa);
            if (aluno != nullptr) {
                int novaMatricula;
                string novoCurso;
                cout << "Digite a nova matrícula: "; cin >> novaMatricula; cin.ignore();
                cout << "Digite o novo curso: "; getline(cin, novoCurso);
                aluno->setMatricula(novaMatricula);
                aluno->setCurso(novoCurso);
            }

            Professor* prof = dynamic_cast<Professor*>(pessoa);
            if (prof != nullptr) {
                float novoSalario;
                string novaDisciplina;
                cout << "Digite o novo salário: "; cin >> novoSalario; cin.ignore();
                cout << "Digite a nova disciplina: "; getline(cin, novaDisciplina);
                prof->setSalario(novoSalario);
                prof->setDisciplina(novaDisciplina);
            }

            cout << "Pessoa atualizada com sucesso!\n";
        } else {
            cout << "Pessoa não encontrada!\n";
        }
    }

    // Método para remover uma pessoa
    void removerPessoa(string nome) {
        int indice = pesquisarPessoa(nome);
        if (indice != -1) {
            delete pessoas[indice]; // Liberar memória
            pessoas.erase(pessoas.begin() + indice);
            cout << "Pessoa removida com sucesso!\n";
        } else {
            cout << "Pessoa não encontrada!\n";
        }
    }

    // Método para gerar relatórios
    void gerarRelatorio() const {
        int totalAlunos = 0;
        int totalProfessores = 0;
        for (Pessoa* pessoa : pessoas) {
            if (dynamic_cast<Aluno*>(pessoa) != nullptr) totalAlunos++;
            if (dynamic_cast<Professor*>(pessoa) != nullptr) totalProfessores++;
        }

        cout << "===== Relatório =====\n";
        cout << "Total de Alunos: " << totalAlunos << "\n";
        cout << "Total de Professores: " << totalProfessores << "\n\n";

        cout << "--- Lista de Alunos ---\n";
        for (Pessoa* pessoa : pessoas) {
            Aluno* aluno = dynamic_cast<Aluno*>(pessoa);
            if (aluno != nullptr) {
                aluno->exibirDetalhes();
                cout << "-----------------------\n";
            }
        }

        cout << "--- Lista de Professores ---\n";
        for (Pessoa* pessoa : pessoas) {
            Professor* prof = dynamic_cast<Professor*>(pessoa);
            if (prof != nullptr) {
                prof->exibirDetalhes();
                cout << "-----------------------\n";
            }
        }
    }

    // Método para salvar dados em arquivo
    void salvarDados() const {
        ofstream arquivo("dados.txt");
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir o arquivo para salvar dados.\n";
            return;
        }

        for (Pessoa* pessoa : pessoas) {
            Aluno* aluno = dynamic_cast<Aluno*>(pessoa);
            Professor* prof = dynamic_cast<Professor*>(pessoa);

            if (aluno != nullptr) {
                // Formato: ALUNO,nome,cpf,rua,cidade,estado,cep,matricula,curso
                arquivo << "ALUNO," 
                        << aluno->getNome() << ","
                        << aluno->getCpf() << ","
                        << aluno->getEndereco().getRua() << ","
                        << aluno->getEndereco().getCidade() << ","
                        << aluno->getEndereco().getEstado() << ","
                        << aluno->getEndereco().getCep() << ","
                        << aluno->getMatricula() << ","
                        << aluno->getCurso() << "\n";
            }
            else if (prof != nullptr) {
                // Formato: PROFESSOR,nome,cpf,rua,cidade,estado,cep,salario,disciplina
                arquivo << "PROFESSOR," 
                        << prof->getNome() << ","
                        << prof->getCpf() << ","
                        << prof->getEndereco().getRua() << ","
                        << prof->getEndereco().getCidade() << ","
                        << prof->getEndereco().getEstado() << ","
                        << prof->getEndereco().getCep() << ","
                        << prof->getSalario() << ","
                        << prof->getDisciplina() << "\n";
            }
        }

        arquivo.close();
        cout << "Dados salvos com sucesso!\n";
    }

    // Método para carregar dados de arquivo
    void carregarDados() {
        ifstream arquivo("dados.txt");
        if (!arquivo.is_open()) {
            cout << "Arquivo de dados não encontrado. Iniciando com base de dados vazia.\n";
            return;
        }

        string linha;
        while (getline(arquivo, linha)) {
            if (linha.empty()) continue;

            // Dividir a linha por vírgulas
            vector<string> campos;
            size_t pos = 0;
            while ((pos = linha.find(',')) != string::npos) {
                campos.push_back(linha.substr(0, pos));
                linha.erase(0, pos + 1);
            }
            campos.push_back(linha); // Último campo

            if (campos[0] == "ALUNO" && campos.size() == 9) {
                string nome = campos[1];
                string cpf = campos[2];
                string rua = campos[3];
                string cidade = campos[4];
                string estado = campos[5];
                string cep = campos[6];
                int matricula = stoi(campos[7]);
                string curso = campos[8];

                Endereco endereco(rua, cidade, estado, cep);
                Pessoa* aluno = new Aluno(nome, cpf, endereco, matricula, curso);
                pessoas.push_back(aluno);
            }
            else if (campos[0] == "PROFESSOR" && campos.size() == 9) {
                string nome = campos[1];
                string cpf = campos[2];
                string rua = campos[3];
                string cidade = campos[4];
                string estado = campos[5];
                string cep = campos[6];
                float salario = stof(campos[7]);
                string disciplina = campos[8];

                Endereco endereco(rua, cidade, estado, cep);
                Pessoa* prof = new Professor(nome, cpf, endereco, salario, disciplina);
                pessoas.push_back(prof);
            }
        }

        arquivo.close();
        cout << "Dados carregados com sucesso!\n";
    }

    // Destrutor para liberar memória alocada
    ~SistemaGerenciador() {
        for (Pessoa* pessoa : pessoas) {
            delete pessoa;
        }
    }
};

//main.cpp
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
        cout << "6. Gerar Relatório\n";
        cout << "7. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

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
                    cout << "Digite o endereço do aluno:\n";
                    cout << "  Rua: "; getline(cin, rua);
                    cout << "  Cidade: "; getline(cin, cidade);
                    cout << "  Estado: "; getline(cin, estado);
                    cout << "  CEP: "; getline(cin, cep);
                    cout << "Digite a matrícula do aluno: "; cin >> matricula; cin.ignore();
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
                    cout << "Digite o endereço do professor:\n";
                    cout << "  Rua: "; getline(cin, rua);
                    cout << "  Cidade: "; getline(cin, cidade);
                    cout << "  Estado: "; getline(cin, estado);
                    cout << "  CEP: "; getline(cin, cep);
                    cout << "Digite o salário do professor: "; cin >> salario; cin.ignore();
                    cout << "Digite a disciplina do professor: "; getline(cin, disciplina);

                    Endereco endereco(rua, cidade, estado, cep);
                    Pessoa* prof = new Professor(nome, cpf, endereco, salario, disciplina);
                    sistema.inserirPessoa(prof);
                    cout << "Professor inserido com sucesso!\n";
                }
                else {
                    cout << "Opção inválida!\n";
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
            case 6: { // Gerar Relatório
                sistema.gerarRelatorio();
                break;
            }
            case 7: { // Sair
                cout << "Salvando dados e saindo do sistema...\n";
                sistema.salvarDados();
                break;
            }
            default:
                cout << "Opção inválida! Por favor, tente novamente.\n";
        }

    } while (opcao != 7);

    return 0;
}