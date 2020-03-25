#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   string s, ans = "";
   map<string, int> M;
   int mx = 0;
   
   cin >> n >> s;

   for (int i = 1; i < n; i++) {
      string a = "";
      a.push_back(s[i - 1]);
      a.push_back(s[i]);
      
      M[a]++;
      if (M[a] > mx) {
         mx  = M[a];
         ans = a;
      }
   }
   
   cout << ans << '\n';
}
