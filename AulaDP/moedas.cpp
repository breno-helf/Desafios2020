#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args);

const int MAXP = 5e4 + 10;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f; // 01111111 em bin

int DP[MAXN][MAXP];
int P, N;
int v[MAXN];

/*
int solve (int i, int p) {
   if (i == 0 && p != 0) return INF;
   if (i < 0 || p < 0) return INF;

   if (DP[i][p] != -1) return DP[i][p];
   
   return DP[i][p] = min(solve(i - 1, p), solve(i, p - v[i]) + 1);
}
*/

int main() {
   while (scanf("%d%d", &P, &N) != EOF) {
      memset(DP, INF, sizeof(DP));
      DP[0][0] = 0;
      if (P == 0) break;
      for (int i = 1; i <= N; i++)
         scanf("%d", v + i);

      for (int i = 1; i <= N; i++) {
         for (int j = 0; j <= P; j++) {
            DP[i][j] = DP[i - 1][j];
            if (j - v[i] >= 0)
               DP[i][j] = min(DP[i][j], DP[i][j - v[i]] + 1);
            //debug("DP[%d][%d] = %d\n", i, j, DP[i][j]);            
         }
      }
      
      int resp = DP[N][P];//solve(N, P);
      if (resp == INF)
         puts("Impossivel");
      else
         printf("%d\n", resp);
   }
}
