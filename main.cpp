#include <iostream> //entrada e saída
#include <limits>   //limpeza de buffer
#include <string>   //strings
    void clear() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    struct Aluno {
        std::string nome;
        int ID{};
        Aluno* next{};
    };


    int main() {
        //ALUNO 1
        auto aluno1 = new Aluno();
        std::cout << "escreva o nome do primeiro aluno: ";
        std::cin >> aluno1 -> nome;
        std::cout << "escreva o ID do primeiro aluno: ";
        std::cin >> aluno1 -> ID;
        aluno1 -> next = nullptr;

        //ALUNO 2
        auto* aluno2 = new Aluno();
        std::cout << "escreva o nome do segundo aluno: ";
        std::cin >> aluno2 -> nome;
        std::cout << "escreva o ID do segundo aluno: ";
        std::cin >> aluno2 -> ID;
        aluno1 -> next = aluno2;


        //ALUNO 3
        auto* aluno3 = new Aluno();
        std::cout << "escreva o nome do terceiro aluno: ";
        std::cin >> aluno3 -> nome;
        std::cout << "escreva o ID do terceiro aluno: ";
        std::cin >> aluno3 -> ID;
        aluno2 -> next = aluno3;
        aluno3 -> next = nullptr;

        Aluno* contador = aluno1;

        while (contador!=nullptr) {
            std::cout << contador -> nome <<" - " << contador -> ID << "\n" << std::endl;
            contador = contador -> next;
        }

        while (aluno1!=nullptr) {
            auto proximo = aluno1 -> next;
            delete aluno1;
            aluno1 = proximo;
        }
        return 0;
        }
