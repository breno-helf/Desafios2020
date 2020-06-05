//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e3 + 10;

int n;

int main() {
   cin >> n;

   while (n--) {
      string s;
      cin >> s;
      stack<char> st;

      bool ok = true;
      for (int c : s) {
         if (c == '(' || c == '[' || c == '{')
            st.push(c);
         else {
            if (st.empty()) {
               ok = false;
               break;
            }
            else if (c == ')' && st.top() == '(') st.pop();
            else if (c == ']' && st.top() == '[') st.pop();
            else if (c == '}' && st.top() == '{') st.pop();
            else {
               ok = false;
               break;
            }            
         }
      }

      if (!st.empty()) ok = false;

      if (ok) cout << "YES\n";
      else cout << "NO\n";
   }

   return 0;
}
