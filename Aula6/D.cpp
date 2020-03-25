#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 212345;

typedef long long int ll;
typedef pair<ll, ll> pii;

ll n, m;
ll a[MAXN];
ll num[MAXN];
vector<pii> op[MAXN];
set<ll> needs, has;

int main() {
   scanf("%lld%lld", &n, &m);
   for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      num[a[i] % m]++;
   }

   ll target = n / m;
   
   for (int i = 0; i < m; i++) {
      debug("num[%d] = %lld\n", i, num[i]);
      if (num[i] < target) needs.insert(i);
      else if (num[i] > target) has.insert(i);
   }

   ll moves = 0;

   for (int x : needs) {
      ll qnt = target - num[x]; // how much x needs
      debug("%lld needs %lld guys\n", x, qnt);
      
      while (qnt > 0) {
         auto it = has.lower_bound(x);
         if (it == has.begin())
            it = has.end();
         --it;

         ll val = *it;

         
         ll have = num[val] - target; // how much *it has
         ll sub = min(have, qnt);
         ll dist = (val < x) ? (x - val) : ((m - val + x) % m);
         debug("%lld has %lld guys to offer! it offered %lld with distance %lld\n", val, have, sub, dist);
                  
         have -= sub;
         qnt -= sub;

         moves += 1LL * sub * dist;
         
         if (have == 0) has.erase(it);
         num[val] -= sub;
         op[val].push_back(pii(sub, dist));         
         assert(sub > 0);
         assert(dist > 0);
      }
   }
   
   printf("%lld\n", moves);
   for (int i = 0; i < n; i++) {
      ll md = a[i] % m;
      if (!op[md].empty()) {
         op[md].back().first--;
         a[i] += op[md].back().second;
         if (op[md].back().first == 0) op[md].pop_back();
      }

      printf("%lld ", a[i]);
   }
   printf("\n");
   
   return 0;
}
