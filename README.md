# Gerenciador de Contatos em C

Este projeto é um sistema de gerenciamento de contatos desenvolvido de forma modular em **Linguagem C**. A aplicação permite o armazenamento, manipulação e análise de dados de contatos, utilizando estruturas personalizadas (`struct`) e funções de validação.

## Descrição do Projeto
O sistema permite o armazenamento de até 100 registros em uma estrutura de dados (`struct`). O objetivo é consolidar os fundamentos da linguagem C, incluindo ponteiros, strings e recursividade, conforme os requisitos da disciplina de Engenharia de Software.

## Funcionalidades
1.  **Cadastrar:** Registro de novos contatos com validação.
2.  **Listar:** Exibição de todos os contatos salvos.
3.  **Buscar por nome:** Localização de registros específicos.
4.  **Editar:** Atualização de dados através de ponteiros.
5.  **Excluir:** Remoção de contatos com reordenação do array.
6.  **Estatísticas (Recursivo):** Função que utiliza recursividade para contar contatos por letra inicial.
7.  **Sair:** Encerramento seguro do programa.

## Detalhes Técnicos e Justificativas
* **Modularização:** O código foi dividido em `main.c`, `contatos.c` e `contatos.h` para garantir organização e evitar *warnings*.
* **Ponteiros:** Utilizamos passagem por referência na edição de contatos para alterar os dados diretamente na memória.
* **Recursividade:** Implementamos a função `contarPorInicial` de forma recursiva para atender ao requisito técnico obrigatório do projeto.

## Equipe e Atribuições (O que cada pessoa fez)
* **Laura Dutra:** * Responsável pela **Documentação Técnica** do projeto.
    * Criou e estruturou todo o arquivo `README.md`.
    * Elaborou os **Slides da Apresentação** final.

* **Manuela:** * Responsável por todo o desenvolvimento do Código-fonte.
    * Implementou a lógica de todas as funções em C e a estrutura modular.
    * Realizou a depuração para garantir que o código compile sem erros.

* **Daniella:** * Responsável pela apresentação do projeto.
    * Realizará a defesa técnica e a demonstração das funcionalidades para o professor.
    * Preparou a explicação sobre os conceitos de ponteiros e recursividade usados no código.
      
## Pré-requisitos

Para compilar e executar este projeto, é necessário ter um **compilador C** instalado e acessível no terminal.

- **Windows:** MinGW-w64 (gcc) ou MSYS2 (gcc) configurado no PATH  
- **Linux:** `gcc` (pacote `build-essential` em Debian/Ubuntu)  

### Verificar se o compilador está instalado
No terminal, execute: (Windows/Linux)

  ```bash
  gcc --version
````

## Compilação e Execução

> Importante: execute os comandos **na pasta raiz do projeto**, onde existem as pastas `src` e `include`.

### Windows (PowerShell)

1. Criar a pasta `build` (onde ficará o executável):

```powershell
mkdir build
```

2. Compilar o projeto (gera `build/contatos.exe`):

```powershell
gcc .\src\main.c .\src\contatos.c -I.\include -o .\build\contatos.exe
```

3. Executar:

```powershell
.\build\contatos.exe
```

### Linux (Terminal)

1. Criar a pasta `build`:

```bash
mkdir -p build
```

2. Compilar (gera `build/contatos`):

```bash
gcc ./src/main.c ./src/contatos.c -I./include -o ./build/contatos
```

3. Executar:

```bash
./build/contatos
```

## Erros comuns

* **"contatos.h: No such file or directory"**

  * Verifique se você está na **raiz do projeto** (onde existe `include/contatos.h`).
  * Verifique se você incluiu o parâmetro `-I.\include` (Windows) ou `-I./include` (Linux).

* **A pasta build não existe**

  * Crie com `mkdir build` (Windows) ou `mkdir -p build` (Linux/macOS).

 ---
**Professor Orientador:** Renato Luan de Sousa Araújo  
**Semestre:** 2026/1 | **Período:** 3°  
**Instituição:** Universidade Evangélica de Goiás (UniEVANGÉLICA)

