## Problema do Ancestral de Nível

**Aluno:** Vinicius Perche de Toledo Agostini

**Supervisor:** Carlos Eduardo Ferreira

------

### Proposta de Trabalho

A query ancestral de nível $\textrm{LA}(u, d)$ devolve, para um nó qualquer $u$ de uma árvore enraizada $T$,  seu ancestral de profundidade $d$. Mais especificamente, o **Problema do Ancestral de Nível** consiste em preprocessar $T$ de forma que possamos responder múltiplas queries rapidamente. 

Este problema pode ser usado, por exemplo, na implementação de algumas estruturas de dados persistentes e de árvores ordenadas com otimização de espaço, que podem ser usadas para representar documentos XML que suportam queries XPath. Além disso, a query $\textrm{LA}$ também é uma operação primitiva oferecidas por algumas estruturas de dados comprimidas e usadas em queries de agregação em intervalo em árvores.

Neste trabalho, estudaremos diversas maneiras diferentes de resolver este problema, analisando cuidadosamente a complexidade de tempo e espaço de cada uma delas, além de fornecer implementações para todas as soluções discutidas, algo escasso na internet atualmente, principalmente em português.

Também farei experimentos para tentar avaliar a performance dos algoritmos na prática e considerarei possíveis *tradeoffs* ao escolher um sobre o outro.

A implementação de todos os algoritmos contará com bons testes para garantir sua corretude, com a ideia de praticar o conceito de Unit Testing ao longo do trabalho.

------

### Cronograma

| **Atividade**                        | Abr  | Mai  | Jun  | Jul  | Ago  | Set  | Out  | Nov  |
| ------------------------------------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| Estudo do problema e seus algoritmos | *    | *    | *    | *    |      |      |      |      |
| Implementação dos algoritmos         |      | *    | *    | *    | *    |      |      |      |
| Escrever testes dos algoritmos       |      | *    | *    | *    | *    |      |      |      |
| Benchmark dos algoritmos             |      |      | *    | *    | *    | *    |      |      |
| Elaboração da monografia             |      |      |      | *    | *    | *    | *    | *    |

