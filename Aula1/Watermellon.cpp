#include<bits/stdc++.h>
using namespace std;

int main() {
   int w;
   cin >> w;
   // Vemos se eh igual a 2 antes de ver se eh par para retirarmos o "Corner Case"
   if (w == 2) { 
      cout << "NO" << endl;
   } else {
      cout << ((w % 2 == 0) ? "YES" : "NO") << endl; 
   }

   return 0;
}
