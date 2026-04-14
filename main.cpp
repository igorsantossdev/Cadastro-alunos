#include <iostream> //in - out
#include <limits> //clear
#include <string>

void clear() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //limpa o buffer depois do enter
}

struct Aluno { //"Classe" aluno
    std::string nome;
    int ID{};
    Aluno* next{};
};

Aluno* cadastro(Aluno* antigo) { //recebe a lista do main
    auto novoAluno = new Aluno(); // novo "objeto" aluno no heap (local usado pra alocação dinâmica)

    std::cout << "Escreva o nome do aluno: ";
    std::getline(std::cin, novoAluno->nome); //getline pra pegar nome completo

    std::cout << "Escreva o ID do aluno: ";
    std::cin >> novoAluno->ID;

    clear();

    novoAluno->next = antigo; //aponta pro aluno anterior e cria o nó
    return novoAluno; //devolve a lista com um aluno
}

void listar(Aluno* lista) {
    if (lista == nullptr) {
        std::cout << "Nenhum aluno cadastrado.\n"; //caso não tenha alunos
        return;
    }
    Aluno* temp = lista; //temp = "temporário", ponteiro pra correr lista
    while (temp != nullptr) {
        std::cout << "Nome: " << temp->nome << " | ID: " << temp->ID << "\n";
        temp = temp->next; // a lista não é mexida pra não perder os endereços
    }
}

int main() {
    Aluno* lista = nullptr;
    int opcao{};

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Cadastrar aluno\n";
        std::cout << "2. Listar alunos\n";
        std::cout << "0. Sair\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;
        clear();

        switch (opcao) {
            case 1:
                lista = cadastro(lista);
                break;
            case 2:
                listar(lista);
                break;
            case 0:
                std::cout << "Encerrando...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    // Liberação de memória
    Aluno* temp = lista;
    while (temp != nullptr) {
        Aluno* proximo = temp->next;
        delete temp;
        temp = proximo;
    }

    return 0;
}