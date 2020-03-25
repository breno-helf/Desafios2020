#include<bits/stdc++.h>
using namespace std;

const int MAXN = 112;

int a[MAXN];

int main() {
   int n, k;
   cin >> n >> k;

   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   int l = 0, r = n - 1;
   int cnt = 0;
   
   while (l < n) {
      if (a[l] <= k) {
         l++;
         cnt++;
      } else break;
   }

   while (r >= l) {
      if (a[r] <= k) {
         r--;
         cnt++;
      } else break;
   }

   cout << cnt << endl;

   return 0;
}
