#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;

   while (scanf("%d", &n) != EOF) {
      vector<int> v;
      for (int i = 0; i < n; i++) {
         int x;
         scanf("%d", &x);
         v.push_back(x);
      }
      
      int cnt = 0;

      for (int i = 0; i < n; i++) {
         for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i]) cnt++;
         }
      }
      
      printf("Minimum exchange operations : %d\n", cnt);
   }

   return 0;
}
