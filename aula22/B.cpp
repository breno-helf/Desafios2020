#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAX = 1e4 + 10;

ll v[MAX];
ll DP[MAX];
int n;

// O(N) no tempo e na memoria
ll solve(int i) {
   if (i >= n) return 0;
   if (DP[i] != -1) return DP[i];

   return DP[i] = max(solve(i + 1), solve(i + 2) + v[i]);
}

/*
  for (int i = 1; i <= n; i++) {
     DP[i] = max(DP[i], DP[i - 1]);
     if (i >= 2) DP[i] = max(DP[i], DP[i - 2] + v[i]);
  }  
 */

int main() {
   int T;
   cin >> T;
   for (int t = 1; t <= T; t++) {
      cin >> n;
      for (int i = 1; i <= n; i++) {
         cin >> v[i];
      }
      memset(DP, 0, sizeof(DP));
      DP[0] = 0;
      for (int i = 1; i <= n; i++) {
         DP[i] = max(DP[i], DP[i - 1]);
         if (i >= 2) DP[i] = max(DP[i], DP[i - 2] + v[i]);
         else DP[i] = max(DP[i], v[i]);         
      }  

      cout << "Case " << t << ": " << DP[n] << '\n';
   }

   return 0;
}
