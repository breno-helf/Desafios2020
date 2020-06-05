#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAX = 5e3 + 10;

string s;

int main() {
   while (true) {
      cin >> s;
      if (s == "0") break;
      int singleChar = 1;
      int doubleChar = 1;
      int cur = 0;
      for (int i = 1; i < s.size(); i++) {
         if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') cur = doubleChar;
         } else {
            if (s[i - 1] == '1') cur = singleChar + doubleChar;
            else if (s[i - 1] == '2' && s[i] > '0' && s[i] <= '6') cur = singleChar + doubleChar;
            else cur = singleChar;            
         }

         doubleChar = singleChar;
         singleChar = cur;
      }

      cout << cur << '\n';
   }
   
}
