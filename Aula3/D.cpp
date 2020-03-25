#include<bits/stdc++.h>
using namespace std;

const int MAXN = 112;

int n;
long long int v[MAXN];
multiset<long long int> S;

void build_set() {
   S.clear();
   for (int i = 0; i < n; i++) {
      S.insert(v[i]);
   }
}

void try_sequence(long long int x, int printNum) {

   // printf("Sequence starting in %d --- ", x);
   
   while(true) {
      auto it = S.find(x);
      if (it == S.end()) {
         // printf("Sequence broke at %d\n", x);
         
         break;
      }

      if (printNum) cout << x << ' ';
      S.erase(it);
      
      if (x % 3 == 0 && S.find(x/3) != S.end()) {
         x /= 3;
      } else {
         x *= 2;
      }
   }

   // for (auto el : S) {
   //    cout << el << ' ';
   // }
   // cout << '\n';
}

int main() {
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }

   for (int i = 0; i < n; i++) {
      build_set();
      try_sequence(v[i], 0);
      if (S.empty()) {
         build_set();
         try_sequence(v[i], 1);
         cout << '\n';
         return 0;
      }
   }
}
