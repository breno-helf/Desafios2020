#include<bits/stdc++.h>
using namespace std;

const int MAXN = 312345;
const int INF = 0x3f3f3f3f;

struct segment {
   int l, r, idx;
   segment(int L = 0, int R = 0, int IDX = 0): l(L), r(R), idx(IDX) {}
};

// Take the greatest
bool sortLeft(const segment& a, const segment& b) {
   if (a.l != b.l) return a.l < b.l;
   if (a.r != b.r) return a.r > b.r;
   return a.idx < b.idx;
}

// Take the smallest
bool sortRight(const segment& a, const segment& b) {
   if (a.r != b.r) return a.r < b.r;
   if (a.l != b.l) return a.l > b.l;
   return a.idx < b.idx;
}

segment L[MAXN], R[MAXN];

int main() {
   int n;
   int ans = 0, mxL, mnR;

   cin >> n;
   
   for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      R[i] = L[i] = segment(l, r, i);
   }

   sort(&L[0], &L[n], sortLeft);
   sort(&R[0], &R[n], sortRight);

   mnR = INF; mxL = -1;
   for (int i = 0; i < n - 1; i++) {
      mnR = min(mnR, L[i].r);
      mxL = max(mxL, L[i].l);
   }
   ans = max(ans, mnR - mxL);

   mnR = INF; mxL = -1;
   for (int i = 1; i < n; i++) {
      mnR = min(mnR, R[i].r);
      mxL = max(mxL, R[i].l);
   }
   ans = max(ans, mnR - mxL);
   
   cout << ans << '\n';
   
   return 0;
   
}
