#include<bits/stdc++.h>
using namespace std;

const int MAXN = 212345;

int v[MAXN];

int main() {
   int n, k;
   cin >> n >> k;

   for (int i = 0; i < n; i++)
      cin >> v[i];

   v[n] = 1e9 + 1;
   
   sort(v, v + n);
  
   int num = --v[k];
   
   if (k == 0) {
      if (num >= 1) cout << num << '\n';
      else cout << -1 << '\n';
   } else {
      if (v[k - 1] <= num && num >= 1) cout << num << '\n';
      else cout << -1 << '\n';
   }
}
