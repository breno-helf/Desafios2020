#include<bits/stdc++.h>
using namespace std;

const int MAXN = 30;

vector<int> pos[MAXN];

int main() {
   int n, k;
   string s;

   cin >> n >> k >> s;
   for (int i = n - 1; i >= 0; i--) {
      pos[s[i] - 'a'].push_back(i);
   }

   int cur = 0;
   for (int i = 0; i < k; i++) {
      while (pos[cur].empty()) cur++;
      int p = pos[cur].back();
      s[p] = '.';
      pos[cur].pop_back();
   }

   for (int i = 0; i < n; i++) {
      if (s[i] != '.') cout << s[i];
   }

   cout << '\n';
   
   return 0;
}
