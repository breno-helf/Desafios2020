#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

string S, R;
int DP[MAXN][MAXN];

int LCS (int n, int m) {
   memset(DP, 0, sizeof(DP));
   
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (S[i - 1] == R[j - 1])
            DP[i][j] = DP[i - 1][j - 1] + 1;
         else
            DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
      }
   }

   return DP[n][m];
}

int main() {
   while(getline(cin, S)) {
      getline(cin, R);
      cout << LCS(S.size(), R.size()) << '\n';
   }
   return 0;
}
