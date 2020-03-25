#include<bits/stdc++.h>
using namespace std;


int main() {
   int n;
   int x, last = 0, cur = 0, mx = 1;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> x;
      if (x > 2*last) {
         mx = max(mx, cur);
         cur = 0;         
      }
      cur++;
      last = x;
   }

   mx = max(cur, mx);
   
   cout << mx << '\n';
   return 0;
   
}
