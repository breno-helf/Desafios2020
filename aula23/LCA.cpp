#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
const int MAXL = 22;

vector<int> adj[MAXN];
int n, q;
int prof[MAXN], pai[MAXN][MAXL];

void dfs(int u, int p) {
   for (int v : adj[u]) {
      if (v != p) {
         prof[v] = prof[u] + 1;
         pai[v][0] = u;
         dfs(v, u);
      }
   }
}

void precalc() {
   for (int v = 0; v < n; v++) {
      for (int p = 1; p < MAXL; p++) {
         pai[v][p] = pai[pai[v][p - 1]][p - 1];
      }
   }   
}

void init() {
   prof[0] = 0;
   dfs(0, 0);
   precalc();
}


int calculateLCA(int v, int u) {
   if (prof[v] > prof[u]) swap(v, u);

   
   for (int p = MAXL - 1; p >= 0; p--) {
      if ((1<<p) <= (prof[u] - prof[v])) {
         u = pai[u][p];
      }
   }

   for (int p = MAXL - 1; p >= 0; p--) {
      if (pai[v][p] != pai[u][p]) {
         u = pai[u][p];
         v = pai[v][p];
      }
   }
   
   if (v != u) return pai[v][0];
   
   return v;
}

int main() {
   while (true) {
      scanf("%d", &n);

      if (n == 0) break;
      
      for (int i = 1; i < n; i++) {
         int a, l;
         scanf("%d%d", &a, &l);
         adj[i].push_back(a);
         adj[a].push_back(i);
      }

      init();
      
      scanf("%d", &q);

      for (int i = 1; i <= q; i++) {
         int s, t;
         scanf("%d%d", &s, &t);

         printf("%d%c", calculateLCA(s, t), (i == q) ? '\n' : ' ');
      }

      for (int i = 0; i < n; i++) adj[i].clear();
   }

   return 0;
}
