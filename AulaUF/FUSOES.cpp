#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int n, k;
int pai[MAX], sz[MAX];

// representante de classe
int raiz (int a) {
   if (pai[a] == a) return a;
   return pai[a] = raiz(pai[a]);
}

void une (int a, int b) {
   a = raiz(a);
   b = raiz(b);
   
   if (a == b) return;
   
   if (sz[b] > sz[a]) swap(a, b);

   pai[b] = a;
   sz[a] += sz[b];   
}

bool find (int a, int b) {
   return (raiz(a) == raiz(b));
}

int main() {
   scanf("%d%d", &n, &k);

   for (int i = 0; i <= n; i++) {
      sz[i] = 1;
      pai[i] = i;
   }
   
   for (int i = 0; i < k; i++) {
      char OP;
      int a, b;
      
      scanf(" %c %d %d", &OP, &a, &b);

      if (OP == 'F') {
         une(a, b);
      } else {
         if (find(a, b))
            puts("S");
         else
            puts("N");
      }
   }
   
   
}
