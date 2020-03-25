#include<bits/stdc++.h>
using namespace std;


int main() {
   int n;
   cin >> n;
   while (n--) {
      string a, b;
      cin >> a >> b;
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      int x = stoi(a);
      int y = stoi(b);
      
      string ans = to_string(x + y);
      reverse(ans.begin(), ans.end());

      cout << stoi(ans) << endl;
   }
   
   
}
