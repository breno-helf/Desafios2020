#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int n, k, m;
vector<int> adj[MAX];
set<int> door[MAX]; // door[v] represents where the keys to open door on vertex v are
vector<int> key[MAX]; // key[v] represents the doors opened by the keys on vertex v
int mark[MAX];

void dfs (int u) {
   mark[u] = 2;
   for (int k : key[u]) {
      door[k].erase(u); // door[k]-- 
      if (mark[k] == 1 && door[k].empty()) // poderia ser door[k] == 0
         dfs(k); // Q.push(k)
   }

   for (int v : adj[u]) {
      if (!mark[v]) {
         if (door[v].empty()) dfs(v);
         else mark[v] = 1;
      }
   }   
}

int main() {

   while (true) {
      scanf("%d%d%d", &n, &k, &m);

      if (n == -1 && k == -1 && m == -1) break;
      
      for (int i = 0; i < k; i++) {
         int a, b;
         scanf("%d%d", &a, &b);
         door[b].insert(a);
         key[a].push_back(b);
      }
      
      for (int i = 0; i < m; i++) {
         int u, v;
         scanf("%d%d", &u, &v);
         
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      
      dfs(1);

      if (mark[n] == 2)
         puts("Y");
      else
         puts("N");

      for (int i = 0; i <= n; i++) {
         door[i].clear();
         key[i].clear();
         adj[i].clear();
         mark[i] = 0;
      }
   }


   return 0;
}
