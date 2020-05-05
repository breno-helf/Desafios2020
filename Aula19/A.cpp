//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int n, m;
int f[MAX];


int main() {
   int ans = INF;
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
      cin >> f[i];
   }
   sort(f, f + m);

   for (int i = 0; (i + n - 1) < m; i++) {
      ans = min(ans, f[i + n - 1] - f[i]);
      //debug("--> Pegando aluno %d ate o %d diff entre %d e %d\n", i, i + n - 1, f[i], f[i + n - 1]);
   }

   cout << ans << endl;
}
