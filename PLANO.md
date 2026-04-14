# Plano de Trabalho — Função Exponenciação f(x, n) = x^n

## Função Computada

- **Definição**: f(x, n) = x^n
- **Entradas**: x (base, inteiro ≥ 0), n (expoente, inteiro ≥ 0)
- **Saída**: resultado da potência (inteiro)
- **Casos especiais**: f(x, 0) = 1 para qualquer x

---

## 👤 Pessoa A — Implementação + Execução

### Etapa 1: Definir a função computada
- [x] f(x, n) = x^n
- [x] Entradas: x (base), n (expoente)
- [x] Saída: x elevado a n
- [x] Caso especial: n = 0 → resultado = 1

### Etapa 2: Implementar os 3 programas

#### 2.1 — Programa Monolítico (C com `goto`)
- [ ] Arquivo: `/monolitico/exponenciacao.c`
- [ ] Fluxo linearizado sem estruturas de controle (apenas `goto` e `if`)
- [ ] Variáveis: x, n, resultado, contador
- [ ] Labels para simular fluxo de máquina

#### 2.2 — Programa Iterativo
- [ ] Arquivo: `/iterativo/exponenciacao.c`
- [ ] Uso de laço `while` ou `for`
- [ ] Multiplicação acumulada

#### 2.3 — Programa Recursivo
- [ ] Arquivo: `/recursivo/exponenciacao.c`
- [ ] Chamada recursiva: f(x, n) = x * f(x, n-1)
- [ ] Condição base: f(x, 0) = 1

### Etapa 3: (BÔNUS) Assembly
- [ ] Arquivo: `/assembly/exponenciacao.asm`
- [ ] Versão monolítica ou iterativa em x86 Assembly (NASM/MASM)
- [ ] Documentar registradores usados e fluxo de execução

### Etapa 4: Testes e exemplos
- [ ] Testar os 3 programas com os mesmos casos:
  - 2^3 = 8
  - 5^0 = 1
  - 3^4 = 81
  - 2^10 = 1024
  - 1^100 = 1
  - 0^5 = 0
- [ ] Garantir que os 3 programas produzem os mesmos resultados

### Etapa 5: Organização do GitHub
- [ ] Estrutura de diretórios criada
- [ ] README completo com instruções de compilação e execução
- [ ] Documentação do uso de IA

---

## 👤 Pessoa B — Teoria + Análise

### Etapa 1: Descrição formal da função
- [ ] Definição matemática:
  - f(x, 0) = 1
  - f(x, n) = x · f(x, n−1), para n > 0
- [ ] Explicação do comportamento esperado

### Etapa 2: Modelagem formal dos programas
- [ ] Transformar cada programa em representação formal:
  - Instruções numeradas
  - Testes condicionais
  - Operações sobre variáveis
- [ ] Formato compatível com Máquina de Traços

### Etapa 3: Máquina de Traços (PARTE MAIS IMPORTANTE — peso 0,75)
- [ ] Construir execução passo a passo para cada programa
- [ ] Mostrar para cada passo:
  - Estado atual (instrução)
  - Valores das variáveis (x, n, resultado, contador)
  - Próxima instrução
- [ ] Formato de sequência de fita

### Etapa 4: Demonstrar equivalência forte
- [ ] Escolher 2 versões (ex: iterativo vs recursivo)
- [ ] Mostrar que os traços são compatíveis
- [ ] Justificar formalmente que computam a mesma função

### Etapa 5: Demonstrar NÃO-equivalência
- [ ] Criar versão com diferença sutil (ex: base `n == 1` em vez de `n == 0`)
- [ ] Mostrar onde os traços divergem
- [ ] Explicar a diferença na função computada

### Etapa 6: Montar apresentação
- [ ] Slides com: definição, códigos, exemplos, traços, conclusão
- [ ] Arquivo em `/apresentacao/`

---

## 🔗 Integração (juntos)
- [ ] Revisar se código bate com a teoria
- [ ] Ensaiar apresentação (ambos devem saber explicar tudo)
- [ ] Documentação final do uso de IA

---

## Cronograma Sugerido

| Fase | Responsável | Descrição |
|------|-------------|-----------|
| 1 | A | Implementar os 3 programas + testes |
| 2 | B | Descrição formal + modelagem |
| 3 | B | Máquina de Traços + equivalência/não-equivalência |
| 4 | A | Bônus Assembly + organização GitHub |
| 5 | A+B | Revisão cruzada + apresentação + ensaio |
