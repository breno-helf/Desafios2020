#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

typedef long long int ll;

const int MAX = 1e5 + 10;

ll n;
ll h[MAX];

int main() {
   while (true) {
      scanf("%lld", &n);
      if (n == 0) break;
      for (int i = 0; i < n; i++)
         scanf("%lld", h + i);

      h[n] = 0;
      stack<int> st;
      ll ans = 0;
      for (int i = 0; i <= n; i++) {
         while (!st.empty() && h[st.top()] > h[i]) {
            int cur = st.top();
            st.pop();

            if (st.empty())
               ans = max(ans, h[cur] * 1LL * i);
            else
               ans = max(ans, h[cur] * 1LL * (i - st.top() - 1));
         }
         
         st.push(i);
      }
      printf("%lld\n", ans);
   }
   
}
