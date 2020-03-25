#include<bits/stdc++.h>
using namespace std;


int main() {
   int n, k;
   string s;
   cin >> n >> k;
   cin >> s;
   
   int breakPoint = n;
   for (int i = 1; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < (n - i); j++) {
         if (s[i + j] != s[j]) {
            ok = false;
            break;
         }
      }

      if (ok == true) {
         breakPoint = i;
         break;
      }      
   }

   //printf("--> %d\n", breakPoint);
   
   string ans = s;
   for (int i = 1; i < k; i++) {
      for (int j = n - breakPoint; j < n; j++) {
         ans += s[j];
      }
   }

   cout << ans << '\n';
   
   return 0;
   
}
