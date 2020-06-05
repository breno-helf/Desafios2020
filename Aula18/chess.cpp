//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

bool board[MAX][MAX];

bool knight(int a, int b, int c, int d) {
   if (abs(a - c) == 1 && abs(b - d) == 2)
      return true;
   if (abs(a - c) == 2 && abs(b - d) == 1)
      return true;

   return false;
}


int main() {
   int X1, Y1, X2, Y2;

   char c1, c2;

   cin >> c1 >> c2;

   X1 = c1 - 'a';
   Y1 = c2 - '1';

   cin >> c1 >> c2;

   X2 = c1 - 'a';
   Y2 = c2 - '1';


   board[X1][Y1] = true;
   board[X2][Y2] = true;

   int ans = 0;
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
         if (i != X1 && j != Y1 &&
             !knight(i, j, X1, Y1) && !knight(i, j, X2, Y2) &&
             board[i][j] == false) {
            ans++;
         }
      }      
   }

   cout << ans << endl;
}

