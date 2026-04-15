/*
 * Programa Iterativo — Exponenciação f(x, n) = x^n
 * Implementado em C com laço while
 *
 * Entradas: x (base), n (expoente) — inteiros >= 0
 * Saída: x elevado a n
 */

#include <stdio.h>

int main() {
    int x, n, r, i;

    printf("=== Programa Iterativo (while) ===\n");
    printf("Digite a base (x): ");
    scanf("%d", &x);
    printf("Digite o expoente (n): ");
    scanf("%d", &n);

    /* Validação do domínio: x >= 0 e n >= 0 */
    if (x < 0 || n < 0) {
        printf("Erro: dominio da funcao exige x >= 0 e n >= 0\n");
    } else {
        r = 1;
        i = 0;

        while (i < n) {
            r = r * x;
            i = i + 1;
        }

        printf("Resultado: %d^%d = %d\n", x, n, r);
    }

    return 0;
}
