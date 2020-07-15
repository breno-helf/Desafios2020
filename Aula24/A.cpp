#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n, c, P[MAX], DP[MAX][2];

/*
int solve(int i, int s) {
   if (i >= n) return 0;
   if (DP[i][s] != -1) return DP[i][s];

   if (s == 0)
      DP[i][s] = max(solve(i + 1, s), solve(i + 1, !s) - c - P[i]);
   else
      DP[i][s] = max(solve(i + 1, s), solve(i + 1, !s) + P[i]);
   
   return DP[i][s];
}
*/

int solve() {
   for (int i = 0; i <= n; i++)
      for (int s = 0; s < 2; s++)
         DP[i][s] = -INF;
   DP[0][0] = 0;
   
   for (int i = 1; i <= n; i++) {
      for (int s = 0; s < 2; s++) {
         if (s == 0)
            DP[i][s] = max(DP[i - 1][s], DP[i - 1][!s] + P[i]);
         if (s == 1)
            DP[i][s] = max(DP[i - 1][s], DP[i - 1][!s] - c - P[i]);
      }
   }
   return DP[n][0];
}


int main() {
   while (scanf("%d%d", &n, &c) != EOF) {
      for (int i = 1; i <= n; i++)
         scanf("%d", P + i);
      memset(DP, -1, sizeof(DP));
      printf("%d\n", solve());
   }   
   return 0;
}
