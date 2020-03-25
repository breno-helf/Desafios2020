// https://codeforces.com/contest/1146/problem/A
#include<bits/stdc++.h>
using namespace std;


int main() {
   string s;
   cin >> s;
   int a = count(s.begin(), s.end(), 'a'), nonA = s.size() - a;
   cout << a + min(a - 1, nonA) << '\n';

   return 0;
}
