//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e1 + 10; 
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int DP[MAX][MAX];
int d[MAX]; // Dimensoes das minhas matrizes

int solve(int i, int j) { // Intervalo [i, j)
   if (j - i <= 2) return 0;
   if (DP[i][j] != INF) return DP[i][j];

   for (int k = i + 1; k < j; k++) {
      int solveE = solve(i, k + 1);
      int solveD = solve(k, j);
      int cur =  d[i] * d[k] * d[j - 1];
      int candidate = solveE + solveD + cur;
      //debug("--> (%d, %d, %d) --> %d + %d + %d = %d\n", i, j, k, solveE, solveD, cur, candidate);
      DP[i][j] = min(DP[i][j], candidate);
   }

   return DP[i][j];
}


// int solveIterativo() {
//    for (int i = 0; i <= n; i++) {
//       DP[i][i + 1] = 0;
//       //DP[i][i] = 0;
//    }

//    for (int i = 0; i < n; i++) {
//       for (int j = i + 1; j < n; j++) {
//          for (int k = i + 1; k < j; k++) {
//             DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j] + d[i] * d[k] * d[j - 1]);
//          }
//       }      
//    }   
// }


int main() {
   memset(DP, INF, sizeof(DP));
   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      scanf("%d", d + i);
   }

   printf("%d\n", solve(0, n));
}
