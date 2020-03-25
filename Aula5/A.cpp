#include<bits/stdc++.h>
using namespace std;

const int MAXN = 112;

int n, k;
map<int, int> M;
int main() {
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      M[x] = i + 1;
   }
      
   if (M.size() < k) cout << "NO\n";
   else {
      cout << "YES\n";
      int cur = 0;
      for (auto x : M) {
         if (cur == k) break;
         cout << x.second << ' ';
         cur++;
      }
      cout << '\n';
   }
   
   return 0;   
}
