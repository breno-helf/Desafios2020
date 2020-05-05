//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 32;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int mx[MAX], mn[MAX];
int d, s;
int ans[MAX];

int main() {
   cin >> d >> s;


   for (int i = 0; i < d; i++)
      cin >> mn[i] >> mx[i];

   bool ok = true;
   for (int i = 0; i < d; i++) {
      if (s >= mn[i]) {
         ans[i] = mn[i];
         s -= mn[i];
      }
      else {
         ok = false;
      }
   }
   
   for (int i = 0; i < d; i++) {
      if (s >= 0 && (mx[i] - ans[i]) > 0) {
         int diff = mx[i] - ans[i];
         ans[i] = min(ans[i] + diff, ans[i] + s);
         s = max(s - diff, 0);
      }
   }
   if (s > 0) ok = false;
   
   if (!ok)
      cout << "NO" << endl;
   else {
      cout << "YES" << endl;
      for (int i = 0; i < d; i++)
         cout << ans[i] << ' ';
      cout << endl;
   }
}
