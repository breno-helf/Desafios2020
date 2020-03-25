// https://codeforces.com/contest/1146/problem/B
#include<bits/stdc++.h>
using namespace std;


int main() {
   string t, A, B, C;
   int numA = 0, pos, n;
   cin >> t;
   n = t.size();
   A = B = C = "";
   
   for (int i = 0; i < n; i++) numA += (t[i] == 'a');

   if ((n - numA) % 2) {
      cout << ":(\n";
      return 0;
   }
   pos = n - (n - numA)/2;
   
   for (int i = 0; i < pos; i++) A += t[i];
   for (int i = pos; i < n; i++) B += t[i];
   for (int i = 0; i < pos; i++) if (t[i] != 'a') C += t[i];

   //cout << pos << '\n' << A << '\n' << B << '\n' << C << '\n';
   
   if (B == C) cout << A << '\n';
   else cout << ":(\n";

   return 0;
}
