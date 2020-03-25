#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
   int q;
   cin >> q;
   for (int i = 0; i < q; i++) {
      ll x, y, k;
      cin >> x >> y >> k;

      ll D = x + y - 2 * min(x, y);
      ll ans = min(x, y);
      ll movs = min(x, y);

      if (movs + D > k) {
         cout << -1 << '\n';
         continue;
      } else {
         ll rest = k - movs - D;
         ans += D - (D % 2);
         //printf("--> %lld %lld --- ", D, rest);
         if (rest % 2 == 0)
            cout << ans + rest << '\n';
         else if (D % 2 == 0)
            cout << max(ans - 1, 0LL) + max(rest - 1, 0LL) << '\n';
         else
            cout << ans + rest << '\n';
      }
   }
   
}
