#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   int sum = 0;
   cin >> n;

   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      sum += x;
   }

   // Somamos 4 para pegar o "teto" da divisao
   cout << (sum + 4) / 5 << endl;

   return 0;
}
