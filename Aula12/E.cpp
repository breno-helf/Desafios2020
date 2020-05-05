#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n;
string s;
string t;
vector<int> BA, AB;
vector<pii> ans;
/*
  for (int u : adj[v]) {
  

  }
 */


int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   
   cin >> n;
   cin >> s;
   cin >> t;

   int a = 0;
   for (char c : s) {
      a += (c == 'a');
   }
   for (char c : t) {
      a += (c == 'a');
   }

   if (a % 2 || (2 * n - a) % 2) {
      cout << -1 << '\n';
      return 0;
   }

   for (int i = 0; i < n; i++) {
      if (s[i] == 'a' && t[i] == 'b')
         AB.push_back(i);
      if (s[i] == 'b' && t[i] == 'a')
         BA.push_back(i);
   }

   for (int i = 0; (i + 1) < AB.size(); i += 2) {
      ans.push_back(pii(AB[i], AB[i + 1]));
   }
   
   for (int i = 0; (i + 1) < BA.size(); i += 2) {
      ans.push_back(pii(BA[i], BA[i + 1]));
   }

   if (AB.size() % 2 && BA.size() % 2) {
      ans.push_back(pii(AB.back(), AB.back()));
      ans.push_back(pii(AB.back(), BA.back()));      
   } else if (AB.size() % 2 || BA.size() % 2) {
      cout << -1 << '\n';
      return 0;
   }

   cout << ans.size() << '\n';
   for (pii p : ans) {
      cout << p.first + 1 << ' ' << p.second + 1 << '\n';    
   }
}
