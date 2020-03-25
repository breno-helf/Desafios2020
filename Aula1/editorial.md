# Editorial Aula 1

- A. Watermellon

"Joao e Maria" tinham uma melancia de w kilos e queriam dividir em 2 partes pares. Bastaria checar se w é par e diferente de 2 (2 é um corner-case)

- B. MaratonIME educates

Temos que dividir todos os membros do maratonIME no menor numero possivel de carros. Para isso precisamos primeiro contar todos os membros (isso é, somar todos os "carros") e então pegar o teto da divisão por 5.

- C. Pizza

Temos que cortar uma pizza redonda em n + 1 pedaços de mesmo tamanho e formato. Para isso sabemos que se n é par podemos fazer (n + 1) / 2 cortes diametralmente e caso contrário devemos fazer n + 1 cortes. Vale atentar que quando n = 0 temos que a resposta também é 0, por que não preciamos cortar (Corner case).

- D. Erasing zeroes

Temos que contar o menor numero de 0 que precisamos retirar da string para que todos os 1`s estejam juntos. Existem varias maneiras de implementar a solução para esse problema, mas uma simples é contar o numero de 0's antes do primeiro 1 e o numero de 0's antes do ultimo 1 (Com 2 while loops) e subtrair esse numero do total de 0's (Poderiamos fazer o mesmo com indices).

- E. Browser

Aqui temos mais um problema de implementacao. Ele pode ser resolvido com sucessivos if's (para quando r = n ou l = 1 ou pos = n ...). Contudo podemos reduzir o numero de ifs calculando a distancia de pos a l e a r e então caso nenhum deles forem na borda vamos para o mais proximo primeiro depois para o mais distante. Caso l ou r for uma borda somente somamos a distancia necessaria e caso ambos forem borda imprimimos 0 (Mostrar código).

