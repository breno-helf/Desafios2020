//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXW = 1e4 + 10;
const int MAXN = 5e2 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int DP[MAXN][MAXW], n, f, e;
int W[MAXN], P[MAXN], t;

int solve(int i, int w) {
   if (w < 0) return INF - 1;
   if (i == 0 && w > 0) return INF - 1;
   
   if (DP[i][w] != INF) return DP[i][w];
   
   DP[i][w] = min(DP[i][w], solve(i - 1, w));
   DP[i][w] = min(DP[i][w], solve(i, w - W[i]) + P[i]);

   return DP[i][w];
}

int main() {
   scanf("%d", &t);
   
   while (t--) {
      scanf("%d%d", &e, &f);
      scanf("%d", &n);
      for (int i = 1; i <= n; i++) {
         scanf("%d%d", P + i, W + i);
      }

      memset(DP, INF, sizeof(DP));
      DP[0][0] = 0;

      // for (int i = 1; i <= n; i++) {
      //    for (int w = 0; w <= (f - e); w++) {
      //       DP[i][w] = min(DP[i][w], DP[i - 1][w]);
      //       if ((w - W[i]) >= 0) DP[i][w] = min(DP[i][w], DP[i][w - W[i]] + P[i]);
      //    }
      // }
      
      int ans = solve(n, f - e);

      if (ans >= INF - 1) {
         puts("This is impossible.");
      } else {
         printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
      }
   }
   
}
