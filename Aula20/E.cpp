#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 10;
const int MAXK = 12;
const int INF = 0x3f3f3f3f;

int n, m, K;
int DP[MAX][MAX][MAXK][2];
char s[MAX], t[MAX];

int main() {
   scanf("%d%d%d", &n, &m, &K);
   scanf(" %s", s + 1);
   scanf(" %s", t + 1);

   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
         for (int k = 0; k <= K; k++)
            for (int p = 0; p <= 1; p++)
               DP[i][j][k][p] = -INF;

   for (int i = 0; i <= max(n, m); i++) {
            DP[i][0][0][0] = DP[0][i][0][0] = 0;
   }
   
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         for (int k = 0; k <= K; k++) {
            for (int p = 0; p <= 1; p++) {
               if (s[i] == t[j]) {
                  if (p != 0)
                     DP[i][j][k][p] = max(DP[i][j][k][p], DP[i - 1][j - 1][k][p] + 1);
                  else if (k != 0)
                     DP[i][j][k][1] = max(DP[i][j][k][1], DP[i - 1][j - 1][k - 1][p] + 1);
               }

               DP[i][j][k][0] = max(DP[i][j][k][0], max(DP[i - 1][j][k][p], DP[i][j - 1][k][p]));
            }
         }
      }
   }

   int ans = 0;

   for (int i = 0; i <= max(n, m); i++) {   
      for (int k = 0; k <= K; k++) {
         for (int p = 0; p <= 1; p++) {
            ans = max(ans, DP[n][i][k][p]);
            ans = max(ans, DP[i][m][k][p]);
         }
      }
   }

   printf("%d\n", ans);      
}
