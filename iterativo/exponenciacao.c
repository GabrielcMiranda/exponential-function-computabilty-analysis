/*
 * Programa Iterativo — Exponenciação f(x, n) = x^n
 * Implementado em C com laço while
 *
 * Entradas: x (base), n (expoente) — inteiros >= 0
 * Saída: x elevado a n
 */

#include <stdio.h>

int main() {
    int x, n, resultado, i;

    printf("=== Programa Iterativo (while) ===\n");
    printf("Digite a base (x): ");
    scanf("%d", &x);
    printf("Digite o expoente (n): ");
    scanf("%d", &n);

    resultado = 1;
    i = 0;

    while (i < n) {
        resultado = resultado * x;
        i = i + 1;
    }

    printf("Resultado: %d^%d = %d\n", x, n, resultado);

    return 0;
}
