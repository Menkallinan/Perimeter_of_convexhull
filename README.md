# Problema 1982 - Fita de Segurança

Este projeto resolve o problema 1982 - Fita de Segurança do site beecrowd, que consiste em calcular o comprimento mínimo de fita necessário para isolar um conjunto de supercomputadores dispostos em um depósito. A solução utiliza o algoritmo do **Convex Hull** para determinar o perímetro do menor polígono convexo que envolve todos os pontos (supercomputadores).

## Descrição do Problema
### Contexto
Novos supercomputadores chegaram aos laboratórios de ciência da computação. Devido ao peso das máquinas, os funcionários não podem movê-las facilmente. Para evitar que pessoas esbarrem ou mexam nos equipamentos, é necessário isolar as máquinas com uma fita de segurança. O objetivo é calcular o comprimento mínimo de fita necessário para isolar todos os supercomputadores, passando apenas pelas máquinas que estão nas bordas.

### Entrada
A entrada consiste em vários casos de teste. Cada caso de teste começa com um inteiro **N** (3 ≤ N ≤ 2000), representando o número de supercomputadores. Em seguida, há **N** linhas, cada uma contendo dois inteiros **X** e **Y** (-2000 ≤ X, Y ≤ 2000), que representam as coordenadas de cada supercomputador no depósito. A entrada termina com **N = 0**, e esse caso não deve ser processado.

### Saída
Para cada caso de teste, o programa deve imprimir a mensagem:

```
Tera que comprar uma fita de tamanho x.
```

Onde **x** é o comprimento total da fita necessária, com duas casas decimais.

### Exemplo
#### Entrada:
```
6
0 8
1 6
8 7
6 6
8 0
3 1
5
1 1
1 4
2 3
4 4
4 1
0
```

#### Saída:
```
Tera que comprar uma fita de tamanho 27.78.
Tera que comprar uma fita de tamanho 12.00.
```

## Solução
### Algoritmo Utilizado
O problema é resolvido utilizando o **algoritmo do Convex Hull (Fecho Convexo)**. O Convex Hull é o menor polígono convexo que envolve todos os pontos dados. O perímetro desse polígono é o comprimento mínimo de fita necessário.

### Passos da Solução
1. **Leitura dos pontos**: As coordenadas dos supercomputadores são lidas e armazenadas em um vetor.
2. **Cálculo do Convex Hull**: O algoritmo **QuickHull** é utilizado para encontrar os pontos que formam o fecho convexo.
3. **Cálculo do perímetro**: O perímetro do polígono convexo é calculado somando as distâncias entre os pontos consecutivos do Convex Hull.
4. **Saída formatada**: O comprimento da fita é exibido com duas casas decimais.

## Como Executar
### Compilação
Compile o código usando um compilador C++ (por exemplo, g++):
```bash
g++ -o convex_hull convex_hull.cpp
```

### Execução
Execute o programa gerado:
```bash
./convex_hull
```

### Entrada e Saída
O programa lê a entrada do terminal e imprime a saída diretamente no terminal. Para testar com o exemplo fornecido, insira os dados manualmente ou use redirecionamento de arquivo:
```bash
./convex_hull < input.txt
```

## Estrutura do Código
- **Função quickHull**: Implementa o algoritmo QuickHull para encontrar os pontos do Convex Hull.
- **Função perimeter**: Calcula a distância entre dois pontos.
- **Função theHull**: Organiza os pontos do Convex Hull e retorna um vetor com eles.
- **Função main**: Lê a entrada, processa cada caso de teste e imprime a saída.

## Dependências
### Bibliotecas Utilizadas
- `<iostream>`: Para entrada e saída.
- `<vector>`: Para armazenar os pontos.
- `<set>`: Para armazenar os pontos do Convex Hull.
- `<cmath>`: Para cálculos matemáticos (distância entre pontos).
- `<algorithm>`: Para operações gerais.

## Limitações
- O algoritmo **QuickHull** tem complexidade **O(n log n)** no melhor caso e **O(n²)** no pior caso, mas é eficiente para o limite de **N ≤ 2000**.
- O programa não verifica se os pontos são colineares, mas o problema garante que **N ≥ 3** e que os pontos não são todos colineares.


## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir **issues** ou enviar **pull requests**.

## Licença
Este projeto está licenciado sob a **MIT License**.

## Referências
- **Convex Hull** - [Wikipedia](https://en.wikipedia.org/wiki/Convex_hull)


