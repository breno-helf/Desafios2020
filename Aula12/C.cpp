#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

typedef long long int ll;

const int MAX = 52;

int n, m;
int grid[MAX][MAX];
int count_row[MAX], count_column[MAX];

int main() {
   scanf("%d%d", &n, &m);

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         scanf(" %d", &grid[i][j]);
         count_row[i] += grid[i][j];
         count_column[j] += grid[i][j];
      }
   }
   
   ll ans = 0;

   for (int i = 0; i < n; i++) {
      int black = count_row[i];
      int white = m - black;

      ans += ((1LL<<black) - 1); // 2 ** black - 1
      ans += ((1LL<<white) - 1); // 2 ** white - 1

      debug("(Row %d) ---> %d %d\n", i, black, white); 
   }

   for (int i = 0; i < m; i++) {
      int black = count_column[i];
      int white = n - black;

      ans += ((1LL<<black) - 1); // 2 ** black - 1
      ans += ((1LL<<white) - 1); // 2 ** white - 1

      debug("(Column %d) ---> %d %d\n", i, black, white);
   }

   ans -= n * m;

   printf("%lld\n", ans);
}
