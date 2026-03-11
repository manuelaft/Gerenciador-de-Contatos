# Gerenciador de Contatos
Projeto prático da disciplina Laboratório de Programação em C

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
