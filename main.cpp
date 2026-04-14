#include <iostream>
#include <limits>
#include <string>

void clear() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct Aluno {
    std::string nome;
    int ID{};
    Aluno* next{};
};

Aluno* cadastro(Aluno* antigo) {
    auto novoAluno = new Aluno();

    std::cout << "Escreva o nome do aluno: ";
    std::getline(std::cin, novoAluno->nome);

    std::cout << "Escreva o ID do aluno: ";
    std::cin >> novoAluno->ID;

    clear();

    novoAluno->next = antigo;
    return novoAluno;
}

void listar(Aluno* lista) {
    if (lista == nullptr) {
        std::cout << "Nenhum aluno cadastrado.\n";
        return;
    }
    Aluno* temp = lista;
    while (temp != nullptr) {
        std::cout << "Nome: " << temp->nome << " | ID: " << temp->ID << "\n";
        temp = temp->next;
    }
}

void editar(Aluno* lista) {
    if (lista == nullptr) {
        std::cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    int idBusca{};
    std::cout << "Digite o ID do aluno que deseja editar: ";
    std::cin >> idBusca;
    clear();

    Aluno* temp = lista;
    while (temp != nullptr) {
        if (temp->ID == idBusca) {
            std::cout << "Aluno encontrado: " << temp->nome << " | ID: " << temp->ID << "\n";

            std::cout << "Novo nome (Enter para manter \"" << temp->nome << "\"): ";
            std::string novoNome;
            std::getline(std::cin, novoNome);
            if (!novoNome.empty()) {
                temp->nome = novoNome;
            }

            std::cout << "Novo ID (0 para manter " << temp->ID << "): ";
            int novoID{};
            std::cin >> novoID;
            clear();
            if (novoID != 0) {
                temp->ID = novoID;
            }

            std::cout << "Aluno atualizado com sucesso.\n";
            return;
        }
        temp = temp->next;
    }

    std::cout << "Aluno com ID " << idBusca << " nao encontrado.\n";
}

int main() {
    Aluno* lista = nullptr;
    int opcao{};

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Cadastrar aluno\n";
        std::cout << "2. Listar alunos\n";
        std::cout << "3. Editar aluno\n";
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
            case 3:
                editar(lista);
                break;
            case 0:
                std::cout << "Encerrando...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    Aluno* temp = lista;
    while (temp != nullptr) {
        Aluno* proximo = temp->next;
        delete temp;
        temp = proximo;
    }

    return 0;
}