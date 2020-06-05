//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e7 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int DP[2][4];
int n;

int main() {
   scanf("%d", &n);
   DP[0][0] = 1;
   // DP[2][4]
   for (int i = 1; i <= n; i++) {
      for (int v = 0; v < 4; v++) {
         DP[i % 2][v] = 0;
         for (int u = 0; u < 4; u++) {
            if (u == v) continue;
            DP[i % 2][v] = (DP[i % 2][v] + DP[(i - 1) % 2][u]) % MOD;
         }
      }
   }

   printf("%d\n", DP[n % 2][0]);
}
