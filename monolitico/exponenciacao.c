/*
 * Programa Monolítico — Exponenciação f(x, n) = x^n
 * Implementado em C com goto (fluxo linearizado)
 *
 * Entradas: x (base), n (expoente) — inteiros >= 0
 * Saída: x elevado a n
 */

#include <stdio.h>

int main() {
    int x, n, r, i;

    printf("=== Programa Monolitico (goto) ===\n");

/* R1: ler(x) → R2 */
    printf("Digite a base (x): ");
    scanf("%d", &x);

/* R2: ler(n) → R3 */
    printf("Digite o expoente (n): ");
    scanf("%d", &n);

/* R3: se (x < 0) → R5 senão → R4 */
    if (x < 0) goto R5;

/* R4: se (n < 0) → R5 senão → R6 */
    if (n < 0) goto R5;
    goto R6;

R5: /* escreva(erro) → RX */
    printf("Erro: dominio da funcao exige x >= 0 e n >= 0\n");
    return 1;

R6: /* r = 1 → R7 */
    r = 1;

/* R7: i = 0 → R8 */
    i = 0;

R8: /* se (i >= n) → R11 senão → R9 */
    if (i >= n) goto R11;

/* R9: r = r * x → R10 */
    r = r * x;

/* R10: i = i + 1 → R8 */
    i = i + 1;
    goto R8;

R11: /* escreva(resultado) → RX */
    printf("Resultado: %d^%d = %d\n", x, n, r);

    return 0;
}
