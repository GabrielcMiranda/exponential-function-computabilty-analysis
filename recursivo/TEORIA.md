# Programa Recursivo — Exponenciação f(x, n) = x^n

## Definição da Função

$$f: \mathbb{N}_0 \times \mathbb{N}_0 \rightarrow \mathbb{N}_0$$

$$f(x, n) = x^n$$

**Definição recursiva matemática**:

$$f(x, 0) = 1$$
$$f(x, n) = x \cdot f(x, n-1), \quad n > 0$$

**Domínio**: x ≥ 0, n ≥ 0

---

## O que é um Programa Recursivo

Um programa recursivo é definido por um **procedimento** que pode invocar a si mesmo. Sua estrutura é composta por:

- **Condição base**: caso em que a recursão para e retorna um valor direto
- **Passo recursivo**: operação executada antes (ou após) da chamada recursiva
- **Chamada recursiva**: invocação do mesmo procedimento com argumento reduzido

O modelo formal usa a notação:

```
P def
  <inicialização>
  R
onde
  R def (se <condição base> então ✓ senão <passo>; R)
```

O símbolo `✓` indica **parada com sucesso** (halt). A cada chamada, o argumento `n` decresce em 1, garantindo que a condição base `n = 0` seja atingida em tempo finito para qualquer `n ∈ ℕ₀`.

---

## Descrição Formal do Programa

```
P def
  ler(x)
  ler(n)
  se (x < 0 || n < 0) então
    escreva("Erro: dominio da funcao exige x >= 0 e n >= 0")
  senão
    r := 1
    R
  fim se
fim programa

onde

  R def (se n = 0 então ✓ senão r := r * x; n := n − 1; R)
```

---

## Correspondência com o Código C

| Construto formal             | Código C                                          |
|------------------------------|---------------------------------------------------|
| `ler(x)`, `ler(n)`           | `scanf("%d", &x)`, `scanf("%d", &n)`              |
| `se (x < 0 \|\| n < 0)`     | `if (x < 0 \|\| n < 0)`                           |
| `escreva(erro)`              | `printf("Erro...")` + `return 1`                  |
| `r := 1`                     | implícito — em C o acumulador é o valor retornado |
| `se n = 0 então ✓`           | `if (n == 0) return 1`                            |
| `r := r * x; n := n − 1; R` | `return x * exponenciacao(x, n - 1)`              |

> **Nota**: o código C usa o valor de retorno da função como acumulador implícito, em vez de uma variável `r` explícita. O resultado é montado na **volta da pilha de chamadas** — `x * exponenciacao(x, n-1)` — o que é equivalente à definição formal.

---

## Pilha de Chamadas para x=2, n=3

```
exponenciacao(2, 3)
  → 2 * exponenciacao(2, 2)
        → 2 * exponenciacao(2, 1)
                → 2 * exponenciacao(2, 0)
                              → 1          ✓ (base)
                → 2 * 1 = 2
        → 2 * 2 = 4
  → 2 * 4 = 8
```

Resultado: 2³ = **8**
