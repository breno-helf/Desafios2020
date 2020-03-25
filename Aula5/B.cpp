#include<bits/stdc++.h>
using namespace std;

const int MAXN = 112;

string S[MAXN];
int n;

bool isSubstr(string& a, string& b) {
   if (a.size() > b.size()) return false;
   for (int i = 0; i < b.size(); i++) {
      if (i + a.size() > b.size()) break;

      bool ok = true;
      for (int j = 0; j < a.size(); j++) {
         if (b[i + j] != a[j]) {
            ok = false;
            break;
         }
      }
      if (ok) return true;
   }
   
   return false;
}

bool cmpSize(string& a, string& b) {
   return a.size() < b.size();
}

int main() {
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> S[i];
   
   sort(&S[0], &S[n], cmpSize);

   for (int i = 1; i < n; i++) {
      if (!isSubstr(S[i - 1], S[i])) {
         cout << "NO\n";
         return 0;
      }
   }

   cout << "YES\n";

   for (int i = 0; i < n; i++) {
      cout << S[i] << '\n';
   }
   
   return 0;
   
}
