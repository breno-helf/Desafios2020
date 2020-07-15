#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args);

typedef long long int ll;

const int MAX = 66;

int n;
ll m;
int ans[MAX];

int main() {
   scanf("%d%lld", &n, &m);

   int l = 1, r = n;
   for (int i = 1; i <= n; i++) {
      ll power;
      if (n - i - 1 <= 0) power = 1;
      else power = (1LL<<(n - i - 1));

      if (m <= power) {
         ans[l++] = i;
      } else {
         ans[r--] = i;
         m -= power;
      }
   }

   for (int i = 1; i <= n; i++) {
      printf("%d%c", ans[i], (i == n) ? '\n' : ' '); 
   }
   return 0;
}
