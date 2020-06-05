#include<bits/stdc++.h>
using namespace std;

const int MAX = 6e3 + 10;
const int INF = 0x3f3f3f3f;

struct turtle {
   int w, s;
   turtle(int W = 0, int S = 0):
      w(W), s(S) {};

   bool operator < (const turtle ot) const {
      if (s != ot.s) return s < ot.s;

      return w < ot.w;
   }   
};


int DP[MAX];
turtle T[MAX];

int main() {
   int n = 0;
   while (scanf("%d %d", &T[n].w, &T[n].s) != EOF)
      n++;

   sort(&T[0], &T[n]);

   memset(DP, INF, sizeof(DP));
   DP[0] = 0;

   int ans = 0;
   
   for (int i = 0; i < n; i++) {
      for (int j = (n - 1); j >= 0; j--) {
         if (T[i].s >= (DP[j] + T[i].w)) {
            DP[j + 1] = min(DP[j + 1], DP[j] + T[i].w);
            ans = max(ans, j + 1);
         }
      }
   }   
-[
   printf("%d\n", ans);
}
