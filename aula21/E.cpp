//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5e2 + 10;
const int MAXF = 9;
const int INF = 0x3f3f3f3f;

int DP[MAX][MAXF]; 
int last[MAX][MAXF][2];
int n;
int c[MAX][MAXF];
char face[MAXF][MAXF] = {"front", "back", "left", "right", "top", "bottom"};

int opposite(int f) {
   if (f % 2 == 0) return f + 1;
   return f - 1;
}

int main() {
   int T = 1;

   while (true) {
      scanf("%d", &n);
      if (n == 0) break;
      
      if (T > 1) printf("\n");
      
      for (int i = 1; i <= n; i++) {
         for (int f = 0; f < 6; f++) {
            scanf("%d", &c[i][f]);
            DP[i][f] = 1;
            last[i][f][0] = last[i][f][1] = 0;
         }
      }

      int ans[2] = {1, 0};
      
      for (int i = 1; i <= n; i++) {
         for (int Fi = 0; Fi < 6; Fi++) {
            for (int j = i - 1; j >= 1; j--) {
               for (int Fj = 0; Fj < 6; Fj++) {
                  if (c[i][Fi] == c[j][opposite(Fj)] && DP[j][Fj] + 1 > DP[i][Fi]) {
                     DP[i][Fi] = DP[j][Fj] + 1;
                     last[i][Fi][0] = j;
                     last[i][Fi][1] = Fj;

                     if (DP[i][Fi] > DP[ans[0]][ans[1]]) {
                        ans[0] = i;
                        ans[1] = Fi;
                     }
                  }
               }
            }
         }
      }
      
      printf("Case #%d\n", T++);
      printf("%d\n", DP[ans[0]][ans[1]]);

      vector<pii> tower;
      
      while (ans[0] != 0) {
         tower.push_back(pii(ans[0], ans[1]));
         int idx = last[ans[0]][ans[1]][0];
         int f = last[ans[0]][ans[1]][1];
         ans[0] = idx; ans[1] = f;
      }
      reverse(tower.begin(), tower.end());

      for (int i = 0; i < tower.size(); i++) {
         printf("%d %s\n", tower[i].first, face[tower[i].second]);
      }
   }
   return 0;
}
