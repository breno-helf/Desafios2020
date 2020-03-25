#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 212345;

int k;
vector<int> a[MAXN];
map<int, pii> sum;

int main() {
   scanf("%d", &k);

   for (int i = 0; i < k; i++) {
      int n;
      int cur = 0;
      scanf("%d", &n);
      for (int j = 0; j < n; j++) {
         int x;
         scanf("%d", &x);
         a[i].push_back(x);
         cur += x;
      }

      for (int j = 0; j < n; j++) {
         int s = cur - a[i][j];
         if (sum.find(s) != sum.end()) {
            int seq = sum[s].first;
            int el = sum[s].second;

            if (seq == i) continue;

            puts("YES");
            printf("%d %d\n%d %d\n", seq + 1, el + 1, i + 1, j + 1);
            return 0;
         } else {
            sum[s] = pii(i, j);
         }         
      }
   }

   puts("NO");

   return 0;
   
}
