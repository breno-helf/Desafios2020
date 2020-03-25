#include<bits/stdc++.h>
using namespace std;


int main() {
   int t;
   cin >> t;
   while(t--) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      if ((y - x) % (a + b) == 0 && (y > x)) {
         cout << (y - x) / (a + b) << '\n';
      } else {
         cout << -1 << '\n';
      }
      
   }
   
   return 0;
}
