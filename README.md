
# Projeto-CRUD-ESCOLAR

1. Criar um sistema **CRUD** (Create, Read, Update, Delete) para cadastro de **estoque/clientes/produtos** ou realizar vendas relacionado a um dos temas sugeridos. O Menu deve possuir no mínimo essas opções:
    1. Inserir
    2. Listar todos
    3. Exibir um (pesquisar por nome e utilizar o índice caso necessário)
    4. Alterar (pesquisar por nome e utilizar o índice caso necessário)
    5. Remover (pesquisar por nome e utilizar o índice caso necessário)
    6. Exibir Relatório
    7. Sair

    **Obs:** faça um método para pesquisar por nome, e reuse ele nas opções, exibir um, alterar, remover. Este método deve retornar o endereço ou o índice do objeto, deve receber como parâmetro o string do nome a ser buscado. 

    **Sugestão de assinatura do método:**

    ```cpp
    Objeto* Pesquisar(std::string nome);
    // ou
    int Pesquisar(std::string nome);
    ```

2. Faça a modelagem das classes que serão utilizadas no sistema utilizando diagrama **UML** de classe.
3. O objeto principal deve ter pelo menos 4 atributos, entre eles um que seja do tipo de outra classe criada pela equipe (composição). Ex.: Endereço, Data, etc.
4. Utilize **herança** com pelo menos 1 superclasse e 2 subclasses.
5. Utilize uma lista/vetor com **polimorfismo**. Implemente pelo menos um método que sobrescreva algum método da superclasse.
6. Utilize uma classe que vai gerenciar as operações CRUD. Não faça na `main()`.
7. Usar bastante **métodos**.
8. Gerar relatório com um resumo das informações. Ex: Relatório de vendas, relatório de estoque, relatório de clientes. No relatório devem ser exibidas informações como, quantidade de elementos cadastrados, valor total, entre outros.
9. O programa deve rodar indefinidamente, até que o usuário escolha sair.
10. Todos os dados armazenados no programa devem ser salvos em arquivo, para que ao sair do programa os dados não se percam. E ao abrir o programa novamente os dados salvos devem ser carregados.
    - Carregar o arquivo automaticamente ao entrar na aplicação.
    - Salvar em arquivo ao finalizar o programa.
    - Todas as operações de inserção, exibição, edição e remoção deve ser realizada no vetor de objetos, e não diretamente no arquivo.
