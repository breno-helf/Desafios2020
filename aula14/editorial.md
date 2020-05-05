# Editorial Aula 14

A. Colecting beats is fun

Todos que fizeram o contest passaram esse problema

B. Parade

É uma repeticao do problema D da aula 7. Isso foi intencional, visto que alguns alunos nao haviam passado o problema naquela ocasiao. É um problema de Pilha.

C. Bycicle race

Podemos ver a pista como um Poligono onde todos os vertices representam uma curva de 90 ou 270 graus. Podemos perceber que as curvas pergiosas sao as de 270 graus, entao podemos montar o poligono e ver quais angulos sao de 270 graus (Há diversos jeitos de fazer isso). Outra solucao eh perceber que a soma dos graus de um poligono de n lados é 180 * (n - 2), então se a for a quantidade de curvas de 90 graus e b a quantidade de curvas de 270 graus, podemos escrever as seguintes formulas: (a + b = n) e (90 * a + 270 * b = 180 * (n - 2)) disso podemos substituir e conseguir a e b em relação a n, que nos daria que b = (n - 4) / 2.

D. Third Party Software 2

Podemos perceber que esse problema é uma variação do problema de [Interval Scheduling](https://en.wikipedia.org/wiki/Interval_scheduling). Não havia a necessidade de conhecer interval scheduling antes para resolver o problema, mas ajudaria a dar uma intuição da solução (Assim como problemas de sorting na mesma linha no começo da disciplina). Podemos ordenar as versões que tinham as funções intervalos (a_i, b_i) por (a_i) de forma crescente e desempatar por (b_i) de forma decrescente. Dessa forma então poderiamos iterar pelas funçoes para decidir as versões que devemos escolher. Para isso vamos guardar a última versão escolhida (No inicio pegamos a versão com o menor inicio e maior fim, isto é, a primeira versão do nosso vetor ordenado), então iteramos no vetor ordenado procurando a primeira versão da qual tem o maior fim e intersecta com a ultima versão escolhida. Por fim vemos se o início da versão atual é maior que o fim da última versão escolhida (isto é, vemos se elas não intersectam), se esse for o caso temos que adicionar a melhor versão encontrada ate agora na resposta (caso ela nao exista, não há resposta). Desenhar ajuda no entendimento da solução.
