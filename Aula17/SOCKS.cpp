#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAX = 2e5 + 10;

int n, m, k;
int c[MAX];
int sz[MAX], p[MAX];
int bestC[MAX];
map<int, int> cmp[MAX];

int raiz(int x) {
   if (x == p[x]) return x;
   return p[x] = raiz(p[x]);
}

bool une(int a, int b) {
   a = raiz(a);
   b = raiz(b);

   if (a == b) return false;

   
   if (sz[a] < sz[b]) swap(a, b);

   p[b] = a;
   sz[a] += sz[b];
   return true;
}

int main() {
   for (int i = 0; i < MAX; i++) {
      sz[i] = 1;
      p[i] = i;
   }
   
   scanf("%d%d%d", &n, &m, &k);
   for (int i = 1; i <= n; i++)
      scanf("%d", c + i);
   
   for (int i = 1; i <= m; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      une(l, r);
   }

   set<int> roots;
   
   for (int i = 1; i <= n; i++) {
      int x = raiz(i);
      cmp[x][c[i]]++;
      if (cmp[x][c[i]] > bestC[x]) bestC[x] = cmp[x][c[i]];
      roots.insert(x);
   }
   
   int ans = 0;

   for (int x : roots) {
      ans += sz[x] - bestC[x];
   }

   printf("%d\n", ans);
}
