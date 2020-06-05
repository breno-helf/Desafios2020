//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2e3 + 10;

int n;
int v[MAX];
ll DP[MAX][MAX];

ll solve(int l, int r) {
   int a = n - r + l;
   if (r == l) return a * v[l];
   if (l > r) return 0;
   if (DP[l][r] != -1) return DP[l][r];

   DP[l][r] = 0;
   
   DP[l][r] = max(DP[l][r], max(solve(l + 1, r) + v[l] * a, solve(l, r - 1) + v[r] * a));

   return DP[l][r];
}

int main() {
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }
   memset(DP, -1, sizeof(DP));
      
   cout << solve(0, n - 1) << '\n';
}
