#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
const int MAXL = 22;

vector<pii> adj[MAXN];
int n, q;
int prof[MAXN], pai[MAXN][MAXL];
ll  cost[MAXN][MAXL];

void dfs(int u, int p) {
   for (pii e : adj[u]) {
      int v = e.first, w = e.second;
      if (v != p) {
         prof[v] = prof[u] + 1;
         pai[v][0] = u;
         cost[v][0] = w;
         dfs(v, u);
      }
   }
}

void precalc() {
   for (int v = 0; v < n; v++) {
      for (int p = 1; p < MAXL; p++) {
         pai[v][p] = pai[pai[v][p - 1]][p - 1];
         cost[v][p] = cost[pai[v][p - 1]][p - 1] + cost[v][p - 1];
      }
   }   
}

ll calculateCostLCA(int v, int u) {
   if (prof[v] > prof[u]) swap(v, u);

   ll ans = 0;
   
   for (int p = MAXL - 1; p >= 0; p--) {
      if ((1<<p) <= (prof[u] - prof[v])) {
         ans += cost[u][p];
         u = pai[u][p];
      }
   }

   for (int p = MAXL - 1; p >= 0; p--) {
      if (pai[v][p] != pai[u][p]) {
         ans += cost[v][p] + cost[u][p];
         u = pai[u][p];
         v = pai[v][p];
      }
   }

   if (v != u) ans += cost[v][0] + cost[u][0];
   
   return ans;
}

void init() {
   prof[0] = 0;
   dfs(0, 0);
   precalc();
}

int main() {
   while (true) {
      scanf("%d", &n);

      if (n == 0) break;
      
      for (int i = 1; i < n; i++) {
         int a, l;
         scanf("%d%d", &a, &l);
         adj[i].push_back(pii(a, l));
         adj[a].push_back(pii(i, l));
      }

      init();
      
      scanf("%d", &q);

      for (int i = 1; i <= q; i++) {
         int s, t;
         scanf("%d%d", &s, &t);

         printf("%lld%c", calculateCostLCA(s, t), (i == q) ? '\n' : ' ');
      }

      for (int i = 0; i < n; i++) adj[i].clear();
   }

   return 0;
}
