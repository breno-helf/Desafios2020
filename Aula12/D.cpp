


sieve() {
   for (int i = 2; i <= n; i++) {
      if (crivo[i] == 0) {
         for (int k = i; k <= n; k *= i) {
            pergunta.push_back(k);
         }         
      }      
   }   
}
