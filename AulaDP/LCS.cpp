#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

string S, R;
int n, m;
int DP[MAXN][MAXN];

int LCS () {
   for (int i = 0; i <= (max(n, m)); i++)
      DP[0][i] = DP[i][0] = 0;
   
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (S[i - 1] == R[j - 1])
            DP[i][j] = DP[i - 1][j - 1] + 1;

         DP[i][j] = max(DP[i][j], DP[i - 1][j]);
         DP[i][j] = max(DP[i][j], DP[i][j - 1]);
      }
   }

   return DP[n][m];
}

int main() {
   cin >> S >> R;
   n = S.size(); m = R.size();

   cout << LCS() << endl;
   return 0;
}
