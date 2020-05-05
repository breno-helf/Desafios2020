#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

typedef long long int ll;

const int MAX = 1e5 + 10;

ll n;
ll h[MAX];
ll L[MAX]; // How much I can expand for the left
ll R[MAX]; // How much I can expand for the right
stack<int> st;

int main() {
   while (true) {
      scanf("%lld", &n);
      if (n == 0) break;
      for (int i = 0; i < n; i++)
         scanf("%lld", h + i);
            
      for (int i = 0; i < n; i++) {
         while (!st.empty() && h[st.top()] >= h[i]) st.pop();

         if (st.empty()) L[i] = i;
         else L[i] = i - st.top() - 1;
         st.push(i);
      }
      while (!st.empty()) st.pop();
      
      for (int i = n - 1; i >= 0; i--) {
         while (!st.empty() && h[st.top()] >= h[i]) st.pop();

         if (st.empty()) R[i] = n - 1 - i;
         else R[i] = st.top() - i - 1;
         st.push(i);
      }
      while (!st.empty()) st.pop();
      
      ll ans = 0;
      for (int i = 0; i < n; i++) {
         //debug("--> %d %lld %lld\n", i, L[i], R[i]);
         ans = max(ans, h[i] * (L[i] + R[i] + 1LL));
      }

      printf("%lld\n", ans);
   }
   
}
