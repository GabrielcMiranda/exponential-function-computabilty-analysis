; ===========================================================================
; Programa Monolítico em Assembly — Exponenciação f(x, n) = x^n
; NASM x86_64, Windows (MinGW) — linkado com a C runtime (printf, scanf)
;
; Entradas: x (base), n (expoente) — inteiros >= 0
; Saída: x elevado a n
;
; Compilar e linkar:
;   nasm -f win64 exponenciacao.asm -o exponenciacao.obj
;   gcc exponenciacao.obj -o exponenciacao.exe -lmsvcrt
; ===========================================================================

default rel

section .data
    msg_titulo  db "=== Programa Monolitico (Assembly) ===", 10, 0
    msg_base    db "Digite a base (x): ", 0
    msg_exp     db "Digite o expoente (n): ", 0
    fmt_in      db "%d", 0
    msg_erro    db "Erro: dominio da funcao exige x >= 0 e n >= 0", 10, 0
    fmt_out     db "Resultado: %d^%d = %d", 10, 0

section .bss
    x   resd 1          ; base
    n   resd 1          ; expoente
    r   resd 1          ; resultado (acumulador)
    i   resd 1          ; contador

section .text
    extern printf
    extern scanf
    global main

main:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32             ; shadow space (Windows x64 calling convention)

    ; --- Título ---
    lea     rcx, [msg_titulo]
    call    printf

; ---------------------------------------------------------------
; R1: faça ler(x)                                    vá para R2
; ---------------------------------------------------------------
    lea     rcx, [msg_base]
    call    printf
    lea     rcx, [fmt_in]
    lea     rdx, [x]
    call    scanf

; ---------------------------------------------------------------
; R2: faça ler(n)                                    vá para R3
; ---------------------------------------------------------------
    lea     rcx, [msg_exp]
    call    printf
    lea     rcx, [fmt_in]
    lea     rdx, [n]
    call    scanf

; ---------------------------------------------------------------
; R3: se (x < 0) então                  vá para R5 senão vá para R4
; ---------------------------------------------------------------
    mov     eax, [x]
    cmp     eax, 0
    jl      R5                  ; x < 0 → R5

; ---------------------------------------------------------------
; R4: se (n < 0) então                  vá para R5 senão vá para R6
; ---------------------------------------------------------------
    mov     eax, [n]
    cmp     eax, 0
    jl      R5                  ; n < 0 → R5
    jmp     R6                  ; senão → R6

; ---------------------------------------------------------------
; R5: escreva("erro")                                vá para RX
; ---------------------------------------------------------------
R5:
    lea     rcx, [msg_erro]
    call    printf
    mov     eax, 1              ; código de retorno = 1 (erro)
    jmp     RX

; ---------------------------------------------------------------
; R6: faça r = 1                                     vá para R7
; ---------------------------------------------------------------
R6:
    mov     dword [r], 1

; ---------------------------------------------------------------
; R7: faça i = 0                                     vá para R8
; ---------------------------------------------------------------
    mov     dword [i], 0

; ---------------------------------------------------------------
; R8: se (i >= n) então                 vá para R11 senão vá para R9
; ---------------------------------------------------------------
R8:
    mov     eax, [i]
    cmp     eax, [n]
    jge     R11                 ; i >= n → R11

; ---------------------------------------------------------------
; R9: faça r = r * x                                 vá para R10
; ---------------------------------------------------------------
    mov     eax, [r]
    imul    eax, [x]            ; eax = r * x
    mov     [r], eax

; ---------------------------------------------------------------
; R10: faça i = i + 1                                vá para R8
; ---------------------------------------------------------------
    mov     eax, [i]
    inc     eax
    mov     [i], eax
    jmp     R8                  ; → R8

; ---------------------------------------------------------------
; R11: escreva("resultado")                          vá para RX
; ---------------------------------------------------------------
R11:
    lea     rcx, [fmt_out]
    mov     edx, [x]            ; arg 2: x
    mov     r8d, [n]            ; arg 3: n
    mov     r9d, [r]            ; arg 4: r
    call    printf
    xor     eax, eax            ; código de retorno = 0 (sucesso)

; ---------------------------------------------------------------
; RX: parada
; ---------------------------------------------------------------
RX:
    add     rsp, 32
    pop     rbp
    ret
