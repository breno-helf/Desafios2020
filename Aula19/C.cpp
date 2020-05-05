//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 4e3 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int DP[MAX];
int n, a, b, c;
int main() {
   cin >> n >> a >> b >> c;
   DP[c] = DP[b] = DP[a] = 1;

   for (int i = 1; i <= n; i++) {
      if (i - a >= 0 && DP[i - a] > 0)
         DP[i] = max(DP[i], DP[a] + DP[i - a]);
      if (i - b >= 0 && DP[i - b] > 0)
         DP[i] = max(DP[i], DP[b] + DP[i - b]);
      if (i - c >= 0 && DP[i - c] > 0)
         DP[i] = max(DP[i], DP[c] + DP[i - c]);
   }
   
   cout << DP[n] << endl;
}
