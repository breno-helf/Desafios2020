//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
ll resp, t[MAX];

int main() {
   int c;
   scanf("%d", &c);

   while (c--) {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
         scanf("%lld", t + i);
      sort(t, t + n);
      resp = 0;
      int j = n;

      vector<int> ans;
      while (j >= 4) {
         ll a = t[0], b = t[1];
         ll c = t[j - 2], d = t[j - 1];
         resp += min(2 * a + c + d, a + 2 * b + d);
         if (2 * a + c + d < a + 2 * b + d) {
            ans.pb(a);ans.pb(c);
            ans.pb(a);
            ans.pb(a);ans.pb(d);
            ans.pb(a);
         } else {
            ans.pb(a);ans.pb(b);
            ans.pb(a);
            ans.pb(c);ans.pb(d);
            ans.pb(b);
         }
         j -= 2;
      }
      if (j == 1) {
         resp += t[0];
         ans.pb(t[0]);
      }
      else if (j == 2) {
         resp += t[1];
         ans.pb(t[0]);
         ans.pb(t[1]);
      }
      else if (j == 3) {
         resp += t[0] + t[1] + t[2];
         ans.pb(t[0]); ans.pb(t[2]);
         ans.pb(t[0]);
         ans.pb(t[0]); ans.pb(t[1]);
      }
      printf("%lld\n", resp);
      for (int i = 0; i < ans.size(); i += 3) {
         if (i + 2 >= ans.size()) {
            if (i + 1 >= ans.size()) printf("%d\n", ans[i]);
            else printf("%d %d\n", ans[i], ans[i + 1]);
         } else {
            printf("%d %d\n%d\n", ans[i], ans[i + 1], ans[i + 2]);
         }
      }
      if (c > 0) printf("\n");
   }
}
