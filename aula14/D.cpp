#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args);

const int MAX = 2e5 + 10;

struct version {
   int l, r, id;
   version(int L = 0, int R = 0, int ID = 0):
      l(L), r(R), id(ID) {};

   bool operator < (const version ot) const {
      if (l != ot.l)
         return l < ot.l;
      if (r != ot.r)
         return r > ot.r;
      return id < ot.id;
   };

   bool operator == (const version ot) const {
      return (ot.l == l && ot.r == r && ot.id == id);
   }

   bool operator != (const version ot) const {
      return (ot.l != l || ot.r != r || ot.id != id);
   }
};

const version INVALID_VERSION = version(-1, -1, -1);

int n, m;
version v[MAX];
vector<int> ans;

int main() {
   scanf("%d%d", &n, &m);
   for (int i = 0; i < n; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      v[i] = version(l, r, i + 1);
   }
   
   sort(v, v + n);

   if (v[0].l != 1) {
      //debug("Sai 0\n");
      puts("NO");
      return 0;
   }
   
   ans.push_back(v[0].id);
   version last = v[0];
   version best = INVALID_VERSION;
   for (int i = 1; i < n; i++) {
      if (v[i].l > last.r + 1) {
         if (best == INVALID_VERSION) {
            //debug("Sai 1\n");
            puts("NO");
            return 0;
         }

         ans.push_back(best.id);
         last = best;
         best = INVALID_VERSION;
      }

      if (last.r == m) break;
      
      if (v[i].l <= last.r + 1) {         
         if (v[i].r > max(last.r, best.r)) best = v[i];
      } else {
         //debug("Sai 2\n");
         puts("NO");
         return 0;
      }      
   }
   
   if (best != INVALID_VERSION) {
      ans.push_back(best.id);
      last = best;
   }
   
   if (last.r != m) {
      //debug("Sai 3\n");
      puts("NO");
      return 0;
   }
   
   puts("YES");
   printf("%d\n", (int)ans.size());
   for (int id : ans)
      printf("%d ", id); 
   printf("\n");
   
   return 0;
}
