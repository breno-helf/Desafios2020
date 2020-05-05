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

int main() {
   int n;
   cin >> n;
   DP[0][0] = 1;
   DP[0][1] = DP[0][2] = DP[0][3] = 0;
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 4; j++) {
         int val = 0;
         for (int k = 0; k < 4; k++) {
            if (j != k)
               val = (val + DP[(i - 1)%2][k]) % MOD;
         }
         DP[i % 2][j] = val;
      }
   }

   cout << DP[n % 2][0] << endl;
}
