# Programa Monolítico em Assembly — Exponenciação f(x, n) = x^n

## Definição da Função

$$f: \mathbb{N}_0 \times \mathbb{N}_0 \rightarrow \mathbb{N}_0$$

$$f(x, n) = x^n$$

**Domínio**: x ≥ 0, n ≥ 0

---

## Por que Assembly?

Assembly é a linguagem mais próxima da máquina real. Nela, o modelo monolítico aparece de forma **natural**: não existem `while`, `for`, `if-else` ou funções. Todo o controle de fluxo é feito por **saltos condicionais e incondicionais** — exatamente como os rótulos R1–R11 do modelo formal.

O Assembly é, portanto, a representação mais fiel de um programa monolítico.

---

## Registradores e Variáveis

As variáveis são armazenadas em **memória** (seção `.bss`), não em registradores, para manter a correspondência direta com o modelo formal:

| Variável formal | Memória Assembly | Tipo |
|-----------------|------------------|------|
| x (base)        | `[x]`            | dword (32 bits) |
| n (expoente)    | `[n]`            | dword (32 bits) |
| r (resultado)   | `[r]`            | dword (32 bits) |
| i (contador)    | `[i]`            | dword (32 bits) |

O registrador `eax` é usado como **temporário** para carregar valores da memória, fazer operações, e guardar de volta — não representa uma variável do modelo.

---

## Correspondência Formal → Assembly

| Rótulo | Instrução formal                   | Assembly (x86_64)                              |
|--------|-------------------------------------|------------------------------------------------|
| R1     | ler(x)                              | `call scanf` com endereço de `x`               |
| R2     | ler(n)                              | `call scanf` com endereço de `n`               |
| R3     | se (x < 0) → R5 senão → R4         | `cmp eax, 0` + `jl R5`                        |
| R4     | se (n < 0) → R5 senão → R6         | `cmp eax, 0` + `jl R5` + `jmp R6`             |
| R5     | escreva(erro) → RX                  | `call printf` + `jmp RX`                       |
| R6     | r := 1                              | `mov dword [r], 1`                             |
| R7     | i := 0                              | `mov dword [i], 0`                             |
| R8     | se (i >= n) → R11 senão → R9        | `cmp eax, [n]` + `jge R11`                    |
| R9     | r := r * x                          | `imul eax, [x]` + `mov [r], eax`              |
| R10    | i := i + 1 → R8                     | `inc eax` + `mov [i], eax` + `jmp R8`         |
| R11    | escreva(resultado) → RX             | `call printf`                                   |
| RX     | parada                              | `ret`                                           |

### Instruções-chave do Assembly usadas

| Instrução | Significado | Equivalente formal |
|-----------|-------------|-------------------|
| `jmp R8`  | salto incondicional | `vá para R8` |
| `jl R5`   | salto se menor (jump if less) | `se ... então vá para R5` |
| `jge R11` | salto se maior ou igual | `se (i >= n) então vá para R11` |
| `cmp a, b`| compara a com b (sem guardar resultado) | teste condicional |
| `imul a, b`| multiplicação inteira com sinal | `r := r * x` |
| `inc eax` | incrementa em 1 | `i := i + 1` |
| `mov [v], val` | atribui valor à memória | `v := val` |

---

## Fluxo de Execução

O fluxo é **idêntico** ao programa monolítico em C — cada label Assembly (`R5`, `R6`, `R8`, `R11`, `RX`) corresponde exatamente ao rótulo formal de mesmo número. Os rótulos R1, R2, R3, R4, R7, R9, R10 são sequenciais (não precisam de label, o fluxo chega por sequência).

```
R1 → R2 → R3 --[x<0]-→ R5 → RX
               ↓
               R4 --[n<0]-→ R5 → RX
               ↓
               R6 → R7 → R8 --[i>=n]-→ R11 → RX
                             ↑
                            R10 ← R9
```

---

## Como Compilar e Executar

### Pré-requisitos

- **NASM** (Netwide Assembler): `nasm`
- **GCC** (MinGW no Windows): `gcc`

### Compilação

```bash
# 1. Montar o arquivo .asm em objeto .obj
nasm -f win64 assembly/exponenciacao.asm -o assembly/exponenciacao.obj

# 2. Linkar com a C runtime (para printf/scanf)
gcc assembly/exponenciacao.obj -o assembly/exponenciacao.exe
```

### Execução

```bash
./assembly/exponenciacao.exe
```

---

## Convenção de Chamada (Windows x64)

Para chamar funções C (`printf`, `scanf`) a partir do Assembly no Windows x64:

- **Argumentos**: passados em `rcx`, `rdx`, `r8`, `r9` (nessa ordem)
- **Shadow space**: 32 bytes reservados na pilha antes de cada `call`
- **Retorno**: em `eax` / `rax`
- **Alinhamento**: pilha deve estar alinhada em 16 bytes antes do `call`
