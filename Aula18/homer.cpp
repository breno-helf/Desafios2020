//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int DP[MAX];
int n, m, t;

int main() {
   while (scanf("%d%d%d", &n, &m, &t) != EOF) {
      DP[0] = 0;
      int last = 0;
      // DP[min(i - n, i - m)...i]
      for (int i = 1; i <= t; i++) {
         DP[i] = -1;
         if (i >= n && DP[i - n] >= 0)
            DP[i] = max(DP[i], DP[i - n] + 1);
         if (i >= m && DP[i - m] >= 0)
            DP[i] = max(DP[i], DP[i - m] + 1);

         if (DP[i] >= 0) last = i;
      }

      for (int i = 0; i <= t; i++) {
         debug("%d ", DP[i]);
      }
      debug("\n\n");
      
      if (DP[t] >= 0) printf("%d\n", DP[t]);
      else
         printf("%d %d\n", DP[last], t - last);      
   }
   
}
