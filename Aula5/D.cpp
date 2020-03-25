#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)


const int MAX = 212345;

int x[MAX];
unordered_set<int> S;

vector<int> ans;

int main() {
   int n;
   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      scanf("%d", x + i);
      S.insert(x[i]);
   }

   ans = {x[0]};
   
   for (int p = 0; p <= 30; p++) {
      int pow = (1<<p);
      
      for (int i = 0; i < n; i++) {
         if (S.find(x[i] - pow) != S.end()) {
            if (ans.size() < 2) ans = {x[i], x[i] - pow};

            if (S.find(x[i] + pow) != S.end()) {
               ans = {x[i], x[i] - pow, x[i] + pow};
               //debug("1. %d %d\n", x[i], pow);
            }
            
            if (S.find(x[i] - 2 * pow) != S.end()) {
               ans = {x[i], x[i] - pow, x[i] - 2*pow};
               //debug("2. %d %d\n", x[i], pow);
            }
         }

         if (S.find(pow + x[i]) != S.end()) {            
            if (ans.size() < 2) ans = {x[i], pow + x[i]};

            if (S.find(x[i] + 2*pow) != S.end()) {
               ans = {x[i], x[i] + pow, x[i] + 2*pow};
               //debug("3. %d %d\n", x[i], pow);
            }
            
            if (S.find(x[i] - pow) != S.end()) {
               ans = {x[i], x[i] + pow, x[i] - pow};
               //debug("4. %d %d\n", x[i], pow);
            }
         }
         
         if (ans.size() == 3) break;
      }

      if (ans.size() == 3) break;
   }

   printf("%d\n", (int)ans.size());
   for (int el : ans)
      printf("%d ", el);
   printf("\n");

   return 0;
}
