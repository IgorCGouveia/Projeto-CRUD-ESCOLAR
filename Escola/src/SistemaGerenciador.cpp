#include "SistemaGerenciador.h"
#include "Aluno.h"
#include "Pessoa.h"
#include "Professor.h"
#include "Endereco.h"

// M�todo de pesquisa que retorna o �ndice ou -1 se n�o encontrado
int SistemaGerenciador::pesquisarPessoa(string nome) const {
    // Converter o nome para min�sculas para pesquisa case-insensitive
    string nomePesquisa = nome;
    transform(nomePesquisa.begin(), nomePesquisa.end(), nomePesquisa.begin(), ::tolower);

    for (size_t i = 0; i < pessoas.size(); ++i) {
        string nomeAtual = pessoas[i]->getNome();
        transform(nomeAtual.begin(), nomeAtual.end(), nomeAtual.begin(), ::tolower);
        if (nomeAtual == nomePesquisa) return i;
    }
    return -1; // N�o encontrado
}

    // Construtor
SistemaGerenciador::SistemaGerenciador() {}

// M�todo para inserir uma pessoa
void SistemaGerenciador::inserirPessoa(Pessoa* pessoa) {
    pessoas.push_back(pessoa);
}

// M�todo para listar todas as pessoas
void SistemaGerenciador::listarPessoas() const {
    if (pessoas.empty()) {
        cout << "Nenhuma pessoa cadastrada.\n";
        return;
    }
    for (Pessoa* pessoa : pessoas) {
        pessoa->exibirDetalhes();
        cout << "-----------------------\n";
    }
}

// M�todo para exibir uma pessoa espec�fica
void SistemaGerenciador::exibirPessoa(string nome) const {
    int indice = pesquisarPessoa(nome);
    if (indice != -1) {
        pessoas[indice]->exibirDetalhes();
    } else {
        cout << "Pessoa nao encontrada!\n";
    }
}

// M�todo para alterar os dados de uma pessoa
void SistemaGerenciador::alterarPessoa(string nome) {
    int indice = pesquisarPessoa(nome);
    if (indice != -1) {
        Pessoa* pessoa = pessoas[indice];
        string novoNome, novoCpf, novaRua, novaCidade, novoEstado, novoCep;

        cout << "Digite o novo nome: "; getline(cin, novoNome);
        cout << "Digite o novo CPF: "; getline(cin, novoCpf);
        cout << "Digite o novo endere�o:\n";
        cout << "  Rua: "; getline(cin, novaRua);
        cout << "  Cidade: "; getline(cin, novaCidade);
        cout << "  Estado: "; getline(cin, novoEstado);
        cout << "  CEP: "; getline(cin, novoCep);

        pessoa->setNome(novoNome);
        pessoa->setCpf(novoCpf);
        Endereco novoEndereco(novaRua, novaCidade, novoEstado, novoCep);
        pessoa->setEndereco(novoEndereco);

        // Verificar se a pessoa � um Aluno ou Professor para alterar atributos espec�ficos
        Aluno* aluno = dynamic_cast<Aluno*>(pessoa);
        if (aluno != nullptr) {
            string novaMatricula;
            string novoCurso;
            cout << "Digite a nova matr�cula: "; cin >> novaMatricula; cin.ignore();
            cout << "Digite o novo curso: "; getline(cin, novoCurso);
            aluno->setMatricula(novaMatricula);
            aluno->setCurso(novoCurso);
        }

        Professor* prof = dynamic_cast<Professor*>(pessoa);
        if (prof != nullptr) {
            float novoSalario;
            string novaDisciplina;
            cout << "Digite o novo sal�rio: "; cin >> novoSalario; cin.ignore();
            cout << "Digite a nova disciplina: "; getline(cin, novaDisciplina);
            prof->setSalario(novoSalario);
            prof->setDisciplina(novaDisciplina);
        }

        cout << "Pessoa atualizada com sucesso!\n";
    } else {
        cout << "Pessoa n�o encontrada!\n";
    }
}

// M�todo para remover uma pessoa
void SistemaGerenciador::removerPessoa(string nome) {
    int indice = pesquisarPessoa(nome);
    if (indice != -1) {
        delete pessoas[indice]; // Liberar mem�ria
        pessoas.erase(pessoas.begin() + indice);
        cout << "Pessoa removida com sucesso!\n";
    } else {
        cout << "Pessoa n�o encontrada!\n";
    }
}

// M�todo para gerar relat�rios
void SistemaGerenciador::gerarRelatorio() const {
    int totalAlunos = 0;
    int totalProfessores = 0;
    for (Pessoa* pessoa : pessoas) {
        if (dynamic_cast<Aluno*>(pessoa) != nullptr) totalAlunos++;
        if (dynamic_cast<Professor*>(pessoa) != nullptr) totalProfessores++;
    }

    cout << "===== Relat�rio =====\n";
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

// M�todo para salvar dados em arquivo
void SistemaGerenciador::salvarDados() const {
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

// M�todo para carregar dados de arquivo
void SistemaGerenciador::carregarDados() {
    ifstream arquivo("dados.txt");
    if (!arquivo.is_open()) {
        cout << "Arquivo de dados n�o encontrado. Iniciando com base de dados vazia.\n";
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;

        // Dividir a linha por v�rgulas
        vector<string> campos;
        size_t pos = 0;
        while ((pos = linha.find(',')) != string::npos) {
            campos.push_back(linha.substr(0, pos));
            linha.erase(0, pos + 1);
        }
        campos.push_back(linha); // �ltimo campo

        if (campos[0] == "ALUNO" && campos.size() == 9) {
            string nome = campos[1];
            string cpf = campos[2];
            string rua = campos[3];
            string cidade = campos[4];
            string estado = campos[5];
            string cep = campos[6];
            string matricula = campos[7];
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

// Destrutor para liberar mem�ria alocada
SistemaGerenciador::~SistemaGerenciador() {
    for (Pessoa* pessoa : pessoas) {
        delete pessoa;
    }
}
