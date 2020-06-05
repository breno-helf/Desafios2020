//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 6e3 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct turtle {
   int w, s;
   turtle(int W = 0, int S = 0):
      w(W), s(S) {};

   bool operator < (const turtle ot) const {
      if (s != ot.s) return s < ot.s;
      return w < ot.w;
   }
};

int n, DP[MAX];
turtle T[MAX];

int main() {
   n = 0;
   while (scanf("%d %d", &T[n].w, &T[n].s) != EOF) {
      n++;
   }

   memset(DP, INF, sizeof(DP));
   sort(&T[0], &T[n]);

   // for (int i = 0; i < n; i++) {
   //    debug("--> %d %d\n", T[i].w, T[i].s);
   // }
   
   DP[0] = 0;
   int ans = 0;
   for (int i = 0; i < n; i++) {
      //debug("Analisando tartaruga %d (%d %d)\n\n", i, T[i].w, T[i].s);
      for (int j = n; j >= 1; j--) {
         //debug("Vendo se cabe embaixo da pilha de tamanho %d e peso %d\n", j - 1, DP[j - 1]);
         if ((DP[j - 1] + T[i].w) <= T[i].s) {
            DP[j] = min(DP[j], DP[j - 1] + T[i].w);
            //debug("Cabe!\n");
         }

         if (DP[j] != INF) ans = max(ans, j);
      }      
   }

   printf("%d\n", ans);
}
