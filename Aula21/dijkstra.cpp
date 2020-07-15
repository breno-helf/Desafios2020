//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12213;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<pii> adj[MAX];
int dist[MAX], mark[MAX];

void dijkstra() {
   memset(dist, INF, sizeof(dist));
   dist[1] = 0;

   set<pii> Q; // Priority queue

   Q.insert(pii(0, 1));

   while (!Q.empty()) {
      int u = Q.begin()->second;
      Q.erase(Q.begin());

      if (mark[u]) continue;
      mark[u] = 1;

      for (pii e : adj[u]) {
         int v = e.first, w = e.second;

         if (dist[u] + w < dist[v] && mark[u] == 0) {
            if (Q.find(pii(dist[v], v)) != Q.end())
               Q.erase(pii(dist[v], v));
            dist[v] = dist[u] + w;
            Q.insert(pii(dist[v], v));
         }         
      }
   }   
}

int main() {
   int n, m;
   cin >> n >> m;

   for (int i = 0; i < m; i++) {
      int u, v, w;

      cin >> u >> v >> w;

      adj[u].push_back(pii(v, w));
      adj[v].push_back(pii(u, w));
   }
   
   dijkstra();

   printf("%d\n", dist[n]);

   return 0;
}

