# Programa Monolítico — Exponenciação f(x, n) = x^n

## Definição da Função

$$f: \mathbb{N}_0 \times \mathbb{N}_0 \rightarrow \mathbb{N}_0$$

$$f(x, n) = x^n$$

**Domínio**: x ≥ 0, n ≥ 0

---

## O que é um Programa Monolítico

Um programa monolítico é definido como uma sequência finita de **rótulos** (R1, R2, ..., RX), onde cada instrução tem **exatamente uma operação** e um **desvio explícito** para o próximo rótulo. Não há estruturas de controle aninhadas — todo o fluxo é expresso por `vá para Ri` ou `se ... então vá para Ri senão vá para Rj`.

O rótulo **RX** indica a instrução de parada (halt).

Tipos de instrução:
- **Leitura**: `faça ler(v) vá para Ri`
- **Escrita**: `escreva(expr) vá para Ri`
- **Atribuição**: `faça v = expr vá para Ri`
- **Teste**: `se (cond) então vá para Ri senão vá para Rj`

---

## Descrição Formal do Programa

```
R1:  faça ler(x)                                              vá para R2
R2:  faça ler(n)                                              vá para R3
R3:  se (x < 0) então                                         vá para R5  senão vá para R4
R4:  se (n < 0) então                                         vá para R5  senão vá para R6
R5:  escreva("erro: dominio da funcao exige x >= 0 e n >= 0")  vá para RX
R6:  faça r = 1                                               vá para R7
R7:  faça i = 0                                               vá para R8
R8:  se (i >= n) então                                        vá para R11 senão vá para R9
R9:  faça r = r * x                                           vá para R10
R10: faça i = i + 1                                           vá para R8
R11: escreva("resultado: x^n = r")                            vá para RX
```

---

## Correspondência com o Código C

| Rótulo | Instrução formal                             | Código C                                      |
|--------|----------------------------------------------|-----------------------------------------------|
| R1     | ler(x)                                       | `scanf("%d", &x)`                             |
| R2     | ler(n)                                       | `scanf("%d", &n)`                             |
| R3     | se (x < 0) → R5 senão → R4                  | `if (x < 0) goto R5`                          |
| R4     | se (n < 0) → R5 senão → R6                  | `if (n < 0) goto R5; goto R6`                 |
| R5     | escreva(erro)                                | `printf("Erro...")` + `return 1`              |
| R6     | r = 1                                        | `r = 1`                                       |
| R7     | i = 0                                        | `i = 0`                                       |
| R8     | se (i >= n) → R11 senão → R9                 | `if (i >= n) goto R11`                        |
| R9     | r = r * x                                    | `r = r * x`                                   |
| R10    | i = i + 1 → R8                               | `i = i + 1; goto R8`                          |
| R11    | escreva(resultado)                            | `printf("Resultado: %d^%d = %d", x, n, r)`   |
| RX     | parada                                       | `return 0` / `return 1`                       |

Os labels do código C (`R5`, `R6`, `R8`, `R11`) correspondem diretamente aos rótulos formais.

---

## Grafo de Fluxo

```
R1 → R2 → R3 --[x<0]-→ R5 → RX
               ↓
               R4 --[n<0]-→ R5 → RX
               ↓
               R6 → R7 → R8 --[i>=n]-→ R11 → RX
                             ↑
                            R10 ← R9
```
