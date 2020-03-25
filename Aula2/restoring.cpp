// https://codeforces.com/problemset/problem/1154/A
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6;

int x[MAXN];

int main() {
   for (int i = 0; i < 4; i++) {
      scanf("%d", &x[i]);
   }

   sort(x, x + 4);

   int a = x[3] - x[0];
   int b = x[3] - x[1];
   int c = x[3] - x[2];

   printf("%d %d %d\n", a, b, c);

   return 0;
}
