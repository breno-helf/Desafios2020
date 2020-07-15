#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1e5 + 10;
const int MOD = 1e5;

int T, A, B, fib[MAX];
int cnt[MOD];

int main() {
   scanf("%d", &T);

   fib[1] = 0; fib[2] = 1;
   for (int i = 3; i < MAX; i++)
      fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
   
   for (int t = 1; t <= T; t++) {
      scanf("%d%d", &A, &B);
      memset(cnt, 0, sizeof(cnt));
      for (int i = A; i <= A + B; i++)
         cnt[fib[i]]++;

      printf("Case %d:", t);
      
      int p = 0;
      for (int i = 0; i < MOD; i++) {
         while (p < 100 && cnt[i] > 0) {
            printf(" %d", i);
            p++;
            cnt[i]--;
         }         
      }
      printf("\n");
   }
   
   return 0;
}
