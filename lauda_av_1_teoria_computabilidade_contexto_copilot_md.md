# Trabalho de Implementação AV1 – Teoria da Computabilidade

## Informações Gerais

- Disciplina: Teoria da Computabilidade
- Professor: Daniel Leal Souza
- Turmas: CC5MA e CC5NA
- Semestre: 01/2026
- Tema: Programas, Máquinas e Equivalência
- Formato: pesquisa aplicada + implementação + apresentação presencial
- Equipes: até 4 integrantes
- Linguagem: livre; para programa monolítico recomenda-se C com `goto`
- Entrega:
  - Link do repositório GitHub
  - Apresentação usada em sala (PDF, PPTX ou equivalente)
  - Anexos complementares, se houver
- Prazos:
  - CC5MA: 15/04/2026 às 23:59
  - CC5NA: 17/04/2026 às 23:59
- Pontuação: até 3,0 pontos
- Bônus: até 0,5 ponto extra caso o programa monolítico seja implementado em Assembly

---

# Objetivo do Trabalho

A equipe deve:

1. Escolher uma função computacional simples.
2. Implementar a mesma função em três estilos:
   - Programa monolítico
   - Programa iterativo
   - Programa recursivo
3. Aplicar a Máquina de Traços para analisar equivalência forte entre programas.
4. Demonstrar:
   - Um caso de equivalência
   - Um caso de não-equivalência

O foco não é apenas mostrar que os programas geram a mesma saída, mas provar formalmente, via traços, quando dois programas são ou não fortemente equivalentes.

---

# Objetivos Específicos

A equipe deve ser capaz de:

- Distinguir programas monolíticos, iterativos e recursivos
- Implementar a mesma função em diferentes estilos
- Descrever entradas, saídas e comportamento esperado
- Aplicar a Máquina de Traços
- Justificar equivalência e não-equivalência com base nos traços
- Demonstrar a função computada com exemplos

---

# Requisitos Obrigatórios

## 1. Escolha da Função

Escolher uma funcionalidade simples que possa ser implementada nos três estilos.

Exemplos possíveis:

- Fatorial
- Soma dos números de 1 até N
- Potência
- MDC
- Fibonacci
- Verificação de número primo

## 2. Implementação dos Três Programas

A equipe deve implementar a mesma função em:

### Programa Monolítico

Características esperadas:

- Fluxo linear
- Uso explícito de `goto` ou estrutura equivalente
- Sem funções auxiliares sofisticadas

### Programa Iterativo

Características esperadas:

- Uso de laços (`for`, `while`, etc.)
- Estruturas de repetição evidentes

### Programa Recursivo

Características esperadas:

- Chamada recursiva
- Condição-base de parada

---

# O Que Deve Ser Apresentado

Para a função escolhida, apresentar:

- Entradas
- Saídas
- Exemplos de execução
- Comportamento esperado

Exemplo:

```text
Função: calcular fatorial
Entrada: n = 5
Saída: 120
```

---

# Máquina de Traços

A equipe deve:

1. Construir uma representação formal dos programas
2. Produzir os rastros/cadeias de execução
3. Comparar os programas pela Máquina de Traços
4. Exibir a saída em formato de sequência de fita, semelhante ao mostrado em aula

Importante:

- Não basta testar entradas e comparar saídas
- É necessário mostrar como a execução ocorre passo a passo
- A equivalência deve ser justificada formalmente

---

# Equivalência Forte

A equipe deve mostrar um caso em que dois programas são fortemente equivalentes.

Isso ocorre quando:

- Produzem a mesma função
- Seguem traços compatíveis
- Mantêm a mesma lógica formal de computação

Exemplo possível:

- Programa iterativo de fatorial
- Programa recursivo de fatorial

Se os traços forem compatíveis, há equivalência forte.

---

# Não-Equivalência

A equipe também deve apresentar um caso de não-equivalência.

Deve ficar claro em qual ponto os programas divergem:

- Ordem das operações
- Teste realizado
- Condição de parada
- Resultado produzido
- Função computada

Exemplo:

- Dois programas que parecem calcular a mesma coisa, mas um utiliza `n > 1` e outro `n >= 1`, gerando traços diferentes

---

# Requisitos do Repositório GitHub

O repositório deve conter:

```text
/README.md
/monolitico/
/iterativo/
/recursivo/
/apresentacao/
/anexos/
```

O `README.md` deve incluir:

- Integrantes da equipe
- Linguagens utilizadas
- Como compilar e executar
- Organização dos arquivos
- Explicação da função implementada
- Explicação do uso de IA, se houver

---

# Estrutura Recomendada da Apresentação

1. Título do trabalho e integrantes
2. Definição da função computada
3. Entradas e saídas
4. Explicação dos três programas
5. Demonstração do programa monolítico
6. Demonstração do programa iterativo
7. Demonstração do programa recursivo
8. Exemplos de execução
9. Aplicação da Máquina de Traços
10. Caso de equivalência
11. Caso de não-equivalência
12. Conclusão

---

# Uso de Inteligência Artificial

É permitido usar IA como apoio para:

- Pesquisa
- Explicação conceitual
- Escrita
- Revisão
- Geração de código

Mas a equipe deve documentar:

- Qual ferramenta foi usada
- Para qual finalidade
- Quais trechos foram aproveitados
- Quais revisões foram feitas pela equipe

Exemplo de documentação:

```text
Ferramenta: ChatGPT
Uso: geração inicial do programa recursivo e explicação da Máquina de Traços
Revisão: a equipe adaptou o código e validou manualmente os traços
```

---

# Critérios de Avaliação

| Critério | Peso |
|---|---:|
| Definição do problema e aderência ao escopo | 0,45 |
| Implementação dos três programas | 0,60 |
| Aplicação da Máquina de Traços | 0,75 |
| Exemplo de equivalência e não-equivalência | 0,30 |
| Exemplos de execução | 0,30 |
| Organização do material, GitHub, apresentação e IA | 0,60 |

Maior peso da avaliação:

- Máquina de Traços
- Qualidade da análise formal
- Correta caracterização dos três tipos de programa

---

# Checklist Final

- [ ] Escolher uma função computada simples
- [ ] Implementar versão monolítica
- [ ] Implementar versão iterativa
- [ ] Implementar versão recursiva
- [ ] Garantir que os três programas computam a mesma função
- [ ] Preparar exemplos de entrada e saída
- [ ] Construir a descrição formal para a Máquina de Traços
- [ ] Gerar os traços
- [ ] Demonstrar equivalência
- [ ] Demonstrar não-equivalência
- [ ] Organizar o repositório GitHub
- [ ] Criar README
- [ ] Finalizar a apresentação
- [ ] Documentar o uso de IA
- [ ] Garantir que todos os integrantes saibam explicar o trabalho

---

# Sugestão para Copilot

Você pode usar este contexto no Copilot para pedir coisas como:

```text
Implemente a função de fatorial em três versões: monolítica usando goto em C, iterativa e recursiva.
Depois gere uma descrição formal compatível com Máquina de Traços e um exemplo de equivalência e não-equivalência.
```

Ou:

```text
Crie a estrutura de um repositório GitHub para este trabalho, incluindo README, programas e apresentação.
```

