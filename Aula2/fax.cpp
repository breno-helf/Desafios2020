#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(int l, int r, string& s) {
   while (l <= r && s[l] == s[r]) {
      l++; r--;
   }
   if (l > r) return true;

   return false;
}

int main() {
   string s;
   int k, n;
   cin >> s >> k;
   n = s.size();
   if (n % k) {
      cout << "NO\n";
      return 0;
   }
   int sub = n / k;
   for (int i = 0; i < n; i += sub) {
      if (!check_palindrome(i, i + sub - 1, s)) {
         cout << "NO\n";
         return 0;
      }
   }

   cout << "YES\n";
   return 0;
}
