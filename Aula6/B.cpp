#include<bits/stdc++.h>
using namespace std;

const int MAXN = 112;


int main() {
   int n;
   string s;
   vector<int> D;
   
   cin >> n >> s;
   for (int i = 1; i <= n; i++)
      if (n % i == 0) D.push_back(i);

   //printf("%s\n", s.c_str());
   for (int d : D) {
      reverse(s.begin(), s.begin() + d);
      //printf("%d --> %s\n", d, s.c_str());
   }

   cout << s << '\n';
   return 0;
}
