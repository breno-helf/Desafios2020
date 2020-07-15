#include<bits/stdc++.h>
using namespace std;
 
#define deb(args...) //fprintf(stderr,args)
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MAX=512345;
const int INF=0x3f3f3f3f;

int n, m, p;
 
stack<int> s;
 
char br[MAX], op[MAX]; 
int pa[MAX];
int L[MAX], R[MAX];
int D[MAX];

int fixPath(int x) {
   if (D[x] == 1) {
      if (R[x] != -1) return R[x] = fixPath(R[x]);
      else return fixPath(x - 1);
   } else if (D[x] == -1) {
      if (L[x] != -1) return L[x] = fixPath(L[x]);
      else return fixPath(x + 1);
   }

   return x;
}

int main() {
   scanf("%d%d%d", &n, &m, &p);
   scanf(" %s", br);
   scanf(" %s", op);
   
   for (int i = 0; i < n; i++) {
      if (br[i] == '(') s.push(i);
      else {
         pa[s.top()] = i;
         pa[i] = s.top();
         s.pop();
      }
      L[i] = i - 1;
      R[i] = i + 1;
   }
   p--;
   L[0] = -1;
   R[n - 1] = -1;
   
   for (int i = 0; i < m; i++) {
      p = fixPath(p);
      
      if (op[i] == 'L') {
         if (L[p] != -1)
            p = L[p];         
      }
      else if (op[i] == 'R') {
         if (R[p] != -1)
            p = R[p];
      }
      else {
         if (pa[p] > p) {
            R[p] = (pa[p] + 1 < n) ? pa[p] + 1 : -1;
            L[pa[p]] = (p - 1 >= 0) ? p - 1 : -1;
            D[p] = 1;
            D[pa[p]] = -1;

            if (R[p] != -1) p = R[p];
            else p = L[p];
         }
         else {
            L[p] = (pa[p] - 1 >= 0) ? pa[p] - 1 : -1;
            R[pa[p]] = (p + 1 < n) ? p + 1 : -1;
            D[pa[p]] = 1;
            D[p] = -1;

            if (R[p] != -1) p = R[p];
            else p = L[p];
         }
      }
   }
   
   
   int c = 0;
   for (int i=0;i<n;i++) {
      c += D[i];
      if (D[i] == -1) continue;
      if (c == 0) printf("%c", br[i]);
   }
   printf("\n");
   
   return 0;
}
  
