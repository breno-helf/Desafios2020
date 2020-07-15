//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5e3 + 10;
const ll  INF = 0x3f3f3f3f3f3f3f3f;
const ll  MOD = 1000000007;

ll L[MAX], DP[MAX][MAX];
int n, k, t;

ll solve(int i, int c) {
   if (c == 0) return 0;
   if (i >= n || (i + 3*c) > n) return INF;
   if (DP[i][c] != -1) return DP[i][c];

   return DP[i][c] = min(solve(i + 1, c), solve(i + 2, c - 1) + (L[i + 1] - L[i]) * (L[i + 1] - L[i]));
}

int main() {
   scanf("%d", &t);

   while (t--) {
      scanf("%d%d", &k, &n);
      k += 8;

      for (int i = 0; i < n; i++)
         scanf("%lld", L + i);
      
      memset(DP, -1, sizeof(DP));

      printf("%lld\n", solve(0, k));
   }
}
