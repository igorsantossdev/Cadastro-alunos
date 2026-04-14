# Changelog
Todas as alterações notáveis neste projeto serão documentadas neste arquivo.

### [v0.1.0] - 14-04-2026
#### Added
- **Menu interativo:** loop `do-while` no `main` com opções numeradas (1. Cadastrar, 2. Listar, 0. Sair), permitindo múltiplas operações sem reiniciar o programa
- **Função `listar()`:** extração da lógica de impressão para uma função dedicada, com verificação de lista vazia

### [v0.0.1] - 08-04-2026
#### Added
- **Gerenciamento de memória:** implementação de loop de desalocação (`delete`) para garantir a liberação de memória ao final da execução
#### Changed
- **Estrutura de dados:** migração de `std::pair` para `struct Aluno` customizada, permitindo uma representação semântica de dados (nome e ID)
- **Lógica de armazenamento:** substituição de vetores por uma lista encadeada manual com ponteiros
- **Padrão de código:** adoção de inicialização uniforme (`{}`) e uso de `auto` para declaração de ponteiros
#### Fixed
- **Memory leak:** correção de vazamento de memória que ocorria ao alocar objetos no _heap_ sem a devida destruição


## Padrão de changelog
**Added**: Para novos recursos (funcionalidades que não existiam).
**Changed**: Para alterações em funcionalidades já existentes.
**Deprecated**: Para recursos que ainda funcionam, mas serão removidos em breve.
**Removed**: Para recursos que foram efetivamente deletados.
**Fixed**: Para qualquer correção de bug (erros de lógica, crash, etc).
**Security**: Em caso de vulnerabilidades corrigidas.