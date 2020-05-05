#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<int> adj[MAX];
int n;
int prof[MAX];

void dfs(int v, int p) { // v eh o atual, p eh o pai
   for (int u : adj[v]) {
      if (u != p) {
         prof[u] = prof[v] + 1;
         dfs(u, v);         
      }
   }
}

int main() {
   scanf("%d", &n);
   for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   dfs(1, 1);
   int mx = -1, x = -1;
   for (int v = 1; v <= n; v++) {
      if (prof[v] > mx) {
         mx = prof[v];
         x = v;
      }      
   }
   memset(prof, 0, sizeof(prof));
   dfs(x, x);

   mx = -1;

   for (int v = 1; v <= n; v++)
      mx = max(mx, prof[v]);

   printf("%d\n", mx);
}

