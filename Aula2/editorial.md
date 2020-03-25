# Editorial Aula 2

- A. Love A

Precisamos calcular o tamanho da maior string que podemos criar a partir de S que mais da metade (estritamente) dos caracteres sao 'a'. Podemos somente remover caracteres. Seja qtdA a variavel que guarda a quantidade de 'a's e qtdNonA a variavel que guarda a quantidade de nao 'a's, a resposta pode ser (qtdA + min(qtdA - 1, qtdNonA)).


- B. Restoring three numbers

Precisamos descobrir 3 numeros, a, b e c, todos estritamente positivos e nos e dado a + b, a + c, b + c, a + b + c em uma ordem arbitraria. Podemos ordenar os 4 numeros dados e sabemos que  maior eh a + b + c. A partir disso podemos subtrair os menores do maior para obter a, b e c (Vale notar que qualquer resposta eh valida).

- C. Two Rabbits

Temos dois coelhinhos, um que comeca na posicao x e vai para direita em pulos de tamanho a e outro comeca em y e vai para esquerda em pulos de tamanho b. Queremos saber se eles vao se encontrar em algum momento t. Esta eh uma esquecao simples e podemos ver se (y - x) sera um inteiro maior que 0 e em caso positivo basta imprilo (negativo basta imprimir -1).

- D. Mike and Fax

Precisamos decidir se uma string eh uma concatenacao de exatamente k strings palindromas de mesmo tamanho. Sabemos que o tamanho da string deve ser divisivel por k, entao eh recomendavel fazer uma funcao "Checar Palindromo" e checamos se os intervalos sao palindromos.


- E. Hate A

Recebemos uma string t, e precisamos decidir se existe uma string s que forma a string t com o algoritmo dado (s cria s' removendo todos os 'a's de s, entao concatenamos ambas). Aqui o segredo eh descorbir o possivel ponto de divisao de s e s'. Podemos fazer isso da seguinte maneira, contamos o numero de 'a's e entao vemos se o numero de nao 'a's eh par (se n - qtdA eh par). em caso positivo sabemos que o ponto de divisao possivel eh n - (n - qtdA) / 2. entao basta construirmos s e s' e ver se sao iguais.