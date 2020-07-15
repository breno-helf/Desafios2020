#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e3 + 10;
const int INF = 0x3f3f3f3f;

string s, r;
int t;
int DP[MAX][MAX];

int solve(int i, int j) {
   if (DP[i][j] != INF) return DP[i][j];
   if (i == s.size()) return r.size() - j;
   if (j == r.size()) return s.size() - i;

   return DP[i][j] = min(solve(i + 1, j + 1) + (s[i] != r[j]),
                         min(solve(i + 1, j) + 1, solve(i, j + 1) + 1));
}

int main() {
   cin >> t;
   while (t--) {
      cin >> s >> r;

      memset(DP, INF, sizeof(DP));

      DP[0][0] = 0;
      for (int i = 0; i <= max(s.size(), r.size()); i++) {
         DP[i][0] = i;
         DP[0][i] = i;
      }
      
      for (int i = 1; i <= s.size(); i++) {
         for (int j = 1; j <= r.size(); j++) {
            DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);
            DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);
            DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + (s[i - 1] != r[j - 1]));
         }
      }
      
      cout << DP[s.size()][r.size()] << '\n';
   }
}
