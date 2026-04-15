# Exponenciação — Análise de Computabilidade

Trabalho de AV1 — Teoria da Computabilidade (CC5, 01/2026)

## Integrantes

- Carlos Eduardo Cardoso Silva  
- Gabriel Costa de Miranda  
- João Ricardo Silva de Almeida
- Yago Patrick Schnorr Pinto

## Função Computada

**Exponenciação**: f(x, n) = x^n

- **Entradas**: `x` (base, inteiro ≥ 0), `n` (expoente, inteiro ≥ 0)
- **Saída**: x elevado a n (inteiro)
- **Definição recursiva**:
  - f(x, 0) = 1
  - f(x, n) = x · f(x, n−1), para n > 0

### Exemplos

| x | n | Resultado |
|---|---|-----------|
| 2 | 3 | 8 |
| 5 | 0 | 1 |
| 3 | 4 | 81 |
| 2 | 10 | 1024 |
| 1 | 100 | 1 |
| 0 | 5 | 0 |

## Estrutura do Repositório

```
/monolitico/exponenciacao.c    — Programa monolítico (C com goto)
/monolitico/TEORIA.md          — Descrição formal do programa monolítico
/iterativo/exponenciacao.c     — Programa iterativo (C com while)
/iterativo/TEORIA.md           — Descrição formal do programa iterativo
/recursivo/exponenciacao.c     — Programa recursivo (C com chamada recursiva)
/recursivo/TEORIA.md           — Descrição formal do programa recursivo
/assembly/exponenciacao.asm    — (Bônus) Programa monolítico em Assembly x86_64
/assembly/TEORIA.md            — Documentação do Assembly
/apresentacao/                 — Slides da apresentação
/anexos/                       — Anexos complementares
PLANO.md                       — Plano de trabalho
README.md                      — Este arquivo
```

## Como Compilar e Executar

### Pré-requisitos

- GCC (MinGW no Windows ou gcc no Linux/Mac)

### Compilação

```bash
# Monolítico
gcc monolitico/exponenciacao.c -o monolitico/exponenciacao

# Iterativo
gcc iterativo/exponenciacao.c -o iterativo/exponenciacao

# Recursivo
gcc recursivo/exponenciacao.c -o recursivo/exponenciacao

# Assembly (Bônus) — requer NASM + GCC
nasm -f win64 assembly/exponenciacao.asm -o assembly/exponenciacao.obj
gcc assembly/exponenciacao.obj -o assembly/exponenciacao.exe
```

### Execução

```bash
# Qualquer versão — digite base e expoente quando solicitado
./monolitico/exponenciacao
./iterativo/exponenciacao
./recursivo/exponenciacao
./assembly/exponenciacao
```

## Linguagens Utilizadas

- **C** — para os 3 programas (monolítico, iterativo, recursivo)
- **Assembly x86_64** — (bônus) versão monolítica em NASM, linkada com C runtime (Windows x64)

## Uso de Inteligência Artificial

| Ferramenta | Finalidade | Revisão |
|------------|-----------|---------|
| GitHub Copilot (Claude) | Geração inicial dos 3 programas em C, estrutura do repositório, plano de trabalho | A equipe revisou o código, validou a lógica e testou manualmente cada programa |