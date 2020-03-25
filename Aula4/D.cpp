#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAXN = 212345;
const int MAXD = 11;

int k, A[MAXN];
ll modval[MAXN][MAXD];
map<int, int> cnt[MAXD]; 

inline int dig(int x) {
   if (x == 0) return 1;
   
   int cur = 0;
   while (x > 0) {
      x /= 10;
      cur++;
   }

   return cur;
}

int main() {   
   //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
   int n;
   ll ans = 0;  
   scanf("%d %d\n", &n, &k);
   //cin >> n >> k;
   
   for (int i = 0; i < n; i++) {
      scanf("%d", A + i);
      //cin >> A[i];
   }

   for (int i = 0; i < n; i++) {
      modval[i][0] = A[i] % k; // modval[i][j] = (a[i] * 10^j) % k
      
      for (int j = 1; j < MAXD; j++) {
         modval[i][j] = (modval[i][j - 1] * 10) % k;
         if(cnt[j].count(modval[i][j])) // cnt[j][X] = Quantos caras (a[i] * 10^j) mod k  == X 
            cnt[j][modval[i][j]]++;
         else
            cnt[j][modval[i][j]] = 1;
      }      
   }
   
   for (int i = 0; i < n; i++) {
      int d = dig(A[i]);
      int negmod = (k - (A[i] % k)) % k;

      if (cnt[d].count(negmod))
         ans += cnt[d][negmod] - (modval[i][d] == negmod);
   }

   
   printf("%lld\n", ans);
   //cout << ans << '\n';
   return 0;
   
}
