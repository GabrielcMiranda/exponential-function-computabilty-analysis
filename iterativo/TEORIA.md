# Programa Iterativo — Exponenciação f(x, n) = x^n

## Definição da Função

$$f: \mathbb{N}_0 \times \mathbb{N}_0 \rightarrow \mathbb{N}_0$$

$$f(x, n) = x^n$$

**Domínio**: x ≥ 0, n ≥ 0

---

## O que é um Programa Iterativo

Um programa iterativo é construído a partir de quatro construtos formais:

- **Atribuição**: `v := expr`
- **Sequência**: `P1; P2`
- **Condicional**: `se B então P1 senão P2 fim se`
- **Repetição**: `enquanto B faça P fim enquanto`

Não existem desvios explícitos (`goto`), saídas antecipadas (`retorne`, `break`) nem rótulos. Todo o fluxo é determinado exclusivamente pela composição dessas estruturas. A cláusula `senão` é **obrigatória** no condicional — quando a computação principal depende da condição ser falsa, ela vai inteiramente dentro do `senão`.

---

## Descrição Formal do Programa

```
ler(x)
ler(n)
se (x < 0 || n < 0) então
  escreva("Erro: dominio da funcao exige x >= 0 e n >= 0")
senão
  r := 1
  i := 0
  enquanto (i < n) faça
    r := r * x
    i := i + 1
  fim enquanto
  escreva("Resultado: ", x, "^", n, " = ", r)
fim se
fim programa
```

---

## Correspondência com o Código C

| Construto formal                        | Código C                                          |
|-----------------------------------------|---------------------------------------------------|
| `ler(x)`                                | `scanf("%d", &x)`                                 |
| `ler(n)`                                | `scanf("%d", &n)`                                 |
| `se (x < 0 \|\| n < 0) então`           | `if (x < 0 \|\| n < 0)`                           |
| `escreva(erro)`                         | `printf("Erro...")` + `return 1`                  |
| `senão`                                 | bloco `else` (implícito — código após o `if`)     |
| `r := 1`                                | `r = 1`                                           |
| `i := 0`                                | `i = 0`                                           |
| `enquanto (i < n) faça`                 | `while (i < n)`                                   |
| `r := r * x`                            | `r = r * x`                                       |
| `i := i + 1`                            | `i = i + 1`                                       |
| `escreva("Resultado: ", x, "^", n, " = ", r)` | `printf("Resultado: %d^%d = %d\n", x, n, r)` |

> **Nota**: o código C usa `return 1` após o erro, o que é um desvio de implementação aceito em C mas não existe no modelo formal. No modelo formal, o fluxo é controlado inteiramente pelo `senão`.

---

## Estrutura de Blocos

```
ler(x); ler(n)
│
└── se (x < 0 || n < 0)
      ├── então: escreva(erro)
      └── senão:
            r := 1; i := 0
            │
            └── enquanto (i < n)
                  r := r * x
                  i := i + 1
            escreva(resultado)
```
