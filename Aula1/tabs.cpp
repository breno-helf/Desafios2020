#include<bits/stdc++.h>
using namespace std;

int main() {
   int n, pos, l, r;
   cin >> n >> pos >> l >> r;
   int op1 = abs(r - pos);
   int op2 = abs(l - pos);
      
   if (l != 1 && r != n) {
      cout << min(op1, op2) + r - l + 2 << endl;
   } else if (l != 1) {
      cout << op2 + 1 << endl;
   } else if (r != n) {
      cout << op1 + 1 << endl;
   } else {
      cout << 0 << endl;
   }
   
   return 0;   
}
