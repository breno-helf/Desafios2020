#include<bits/stdc++.h>
using namespace std;

const int MAXN = 212345;

int n, a, b, k;
int h[MAXN];
int sk[MAXN]; // skips required to win;

int main() {
   scanf("%d %d %d %d", &n, &a, &b, &k);
   
   for (int i = 0; i < n; i++) {
      scanf("%d", h + i);
      h[i] %= (a + b);
      if (h[i] == 0) h[i] = a + b;
      
      //printf("%d ", h[i]);
      if (h[i] <= a)
         sk[i] = 0;
      else
         sk[i] = (h[i] - 1) / a;
   }

   sort(sk, sk + n);
   int resp = 0;

   for (int i = 0; i < n; i++) {
      if (sk[i] <= k) {
         resp++;
         k -= sk[i];
      }
   }

   //printf("\n --> %d \n\n", k);
   
   printf("%d\n", resp);
}
