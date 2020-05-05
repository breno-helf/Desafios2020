#include<bits/stdc++.h>
using namespace std;


int main() {   
   string s;
   bool hasSussu = false;
   
   while (cin >> s) {
      if (s == "Sussu") hasSussu = true;
   }
   char ponctuation = s.back();
   s.pop_back();
   hasSussu |= (s == "Sussu");
   
   if (ponctuation == '?') {
      cout << "7" << endl;
      return 0;
   }

   if (hasSussu) {
      cout << "AI SUSSU!" << endl;
      return 0;
   }
   
   cout << "O cara é bom!" << endl;
   return 0;
}
