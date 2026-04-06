#include <iostream> //entrada e saída
#include <limits>   //limpeza de buffer
#include <string>   //strings
#include <vector>   //vetor

    void clear() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

int main() {
        //variaveis
        int ID;
        std::string nome;

        //vetor de alunos
        using Turma = std::vector<std::pair<int, std::string>>;
        Turma grupo1;

        //adicionando alunos
        for (int i = 0; i < 3; i++) {
            std::cout << "Digite o ID e o primeiro nome do aluno (separados apenas por espaço)" << std::endl;
            std::cin >> ID >> nome;
            clear();
            grupo1.emplace_back(ID, nome);
        }

        //imprimindo alunos
        for (int i = 0; i < 3; i++) {
            std::cout << grupo1[i].first << " " << grupo1[i].second << ";\n" << std::endl;
        }

        return 0;
    }


/*OBJETIVOS
     * 1. aprender pair, vector e percorrer lista
     * 2. criar uma lista com ID e nome
     * 3. colocar 3 pessoas
     * 4. percorrer a lista e imprimir os ID e nomes durante a lista
     * 5. o usuário adicionar as pessoas com ID e procurar por ID
     */
