//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e3 + 10;

struct elephant {
   int w, s, id;

   elephant(int W = 0, int S = 0, int ID = 0):
      w(W), s(S), id(ID) {};
   
   bool operator < (const elephant ot) const {
      return w < ot.w;
   }
};

int n;
elephant E[MAX];
int DP[MAX];
int last[MAX];
int best, head;

void solve() {
   for (int i = 0; i < n; i++) {
      DP[i] = 1; last[i] = i;
   
      for (int j = 0; j < i; j++) {
         if (E[j].w < E[i].w && E[j].s > E[i].s && DP[j] + 1 > DP[i]) {
            DP[i] = DP[j] + 1;
            last[i] = j;
         }
      }

      if (DP[i] > best) {
         best = DP[i];
         head = i;
      }
   }
}

int main() {
   int w, s;
   n = 0;
   best = 1, head = 0;
   while (scanf("%d %d", &w, &s) != EOF) {
      E[n] = elephant(w, s, n);
      n++;
   }

   sort(E, E + n);

   // for (int i = 0; i < n; i++) {
   //    debug("-> %d %d %d\n", E[i].w, E[i].s, E[i].id);
   // }
   // debug("\n");
   
   memset(DP, -1, sizeof(DP));
      
   solve();
   
   printf("%d\n", best);

   vector<int> ans;

   while (last[head] != head) {
      ans.push_back(head);
      head = last[head];
   }
   ans.push_back(head);

   reverse(ans.begin(), ans.end());

   for (int i = 0; i < best; i++) {
      printf("%d\n", E[ans[i]].id + 1);
   }

   return 0;
}
