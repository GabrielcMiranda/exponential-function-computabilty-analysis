/*
 * Programa Monolítico — Exponenciação f(x, n) = x^n
 * Implementado em C com goto (fluxo linearizado)
 *
 * Entradas: x (base), n (expoente) — inteiros >= 0
 * Saída: x elevado a n
 */

#include <stdio.h>

int main() {
    int x, n, resultado, contador;

    printf("=== Programa Monolitico (goto) ===\n");
    printf("Digite a base (x): ");
    scanf("%d", &x);
    printf("Digite o expoente (n): ");
    scanf("%d", &n);

    /* Inicialização */
    resultado = 1;
    contador = 0;

/* I1: Teste — contador < n? */
INICIO:
    if (contador >= n) goto FIM;

/* I2: Operação — resultado = resultado * x */
    resultado = resultado * x;

/* I3: Incremento — contador = contador + 1 */
    contador = contador + 1;

/* I4: Desvio incondicional */
    goto INICIO;

FIM:
    printf("Resultado: %d^%d = %d\n", x, n, resultado);

    return 0;
}
