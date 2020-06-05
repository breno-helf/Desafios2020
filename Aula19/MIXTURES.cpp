//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const ll  INF = 0x3f3f3f3f3f3f3f3f;
const ll  MOD = 100;

int n;
int mix[MAX];
ll acc[MAX];
ll DP[MAX][MAX];

void precalc() {
   for (int i = 0; i < n; i++) {
      if (i == 0) acc[i] = 0;
      else acc[i] = acc[i - 1];

      acc[i] = (acc[i] + mix[i]) % MOD;
   }
}

ll sum(int l, int r) {
   if (l == 0) return acc[r];

   return (acc[r] - acc[l - 1] + MOD) % MOD;
}

ll solve(int l, int r) {
   if (r == l) return 0;
   if (l > r) return INF;
   if (DP[l][r] != -1) return DP[l][r];

   DP[l][r] = INF;
   
   for (int i = l; i < r; i++)
      DP[l][r] = min(DP[l][r], solve(l, i) + solve(i + 1, r) + sum(l, i) * sum(i + 1, r));

   return DP[l][r];
}

int main() {
   while (cin >> n) {
      for (int i = 0; i < n; i++) {
         cin >> mix[i];
      }
      memset(DP, -1, sizeof(DP));
      precalc();
      
      cout << solve(0, n - 1) << '\n';
   }
}
