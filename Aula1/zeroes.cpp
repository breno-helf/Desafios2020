#include<bits/stdc++.h>
using namespace std;


string s;


int main() {
   int q = 0;
   cin >> q;
   while (q--) {
      cin >> s;
      
      int st = 0, ed = 0, tot = 0;
      for (int i = 0; i < s.size(); i++) {
         if (s[i] == '0')
            tot++;
      }
      while (st < s.size() && s[st] == '0') st++;
      
      int n = s.size() - 1;
      while (n >= 0 && s[n] == '0') {
         ed++;
         n--;
      }

      //cout << st << " " <<  ed << " " <<  tot << endl;
      
      
      cout << max(tot - st - ed, 0) << endl;
   }
}
