/*
 * Programa Recursivo — Exponenciação f(x, n) = x^n
 * Implementado em C com chamada recursiva
 *
 * Entradas: x (base), n (expoente) — inteiros >= 0
 * Saída: x elevado a n
 *
 * Definição:
 *   f(x, 0) = 1
 *   f(x, n) = x * f(x, n-1)  para n > 0
 */

#include <stdio.h>

int exponenciacao(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return x * exponenciacao(x, n - 1);
}

int main() {
    int x, n, resultado;

    printf("=== Programa Recursivo ===\n");
    printf("Digite a base (x): ");
    scanf("%d", &x);
    printf("Digite o expoente (n): ");
    scanf("%d", &n);

    resultado = exponenciacao(x, n);

    printf("Resultado: %d^%d = %d\n", x, n, resultado);

    return 0;
}
