# Changelog 
Todas as alterações notáveis neste projeto serão documentadas neste arquivo.

### [v0.0.1] - 08-04-2026
#### Added
- **Gerenciamento de memória:** implementação de loop de desalocação (delete) para garantir a liberação de memória ao final da execução
### Changed
- **Estrutura de dados:** migração de std::pair para Struct Aluno customizada, permitindo uma representação semântica de dados (nome e ID)
- **Lógica de Armazenamento:** substituição de vetores por uma lista encadeada manual com ponteiros
- **Padrão de código:** adoção de inicialização uniforme ( {} ) e uso de auto para declaração de ponteiros
### Fixed 
- **Memory leak:** Correção de vazamento de memória que ocorria ao alocar objetos no _heap_ sem a devida destruição 



## Padrão de changelog 
**Added**: Para novos recursos (funcionalidades que não existiam).  
**Changed**: Para alterações em funcionalidades já existentes.  
**Deprecated**: Para recursos que ainda funcionam, mas serão removidos em breve.  
**Removed**: Para recursos que foram efetivamente deletados.  
**Fixed**: Para qualquer correção de bug (erros de lógica, crash, etc).  
**Security**: Em caso de vulnerabilidades corrigidas.  