#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int n, q, T;
int seg[4 * MAX];
int a[MAX];

int mergeNodes(int esq, int dir) {
   return seg[esq] + seg[dir];
}

void build(int no, int l, int r) {
   if (l == r) {
      seg[no] = a[l];
      return;
   }

   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   build(esq, l, mid);
   build(dir, mid + 1, r);

   seg[no] = mergeNodes(esq, dir);
}

void pointUpdate(int no, int l, int r, int pos, int val) {
   if (l == r && l == pos) {
      seg[no] = val;
      a[pos] = val;
      return;
   }
   
   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   if (pos <= mid)
      pointUpdate(esq, l, mid, pos, val);
   else
      pointUpdate(dir, mid + 1, r, pos, val);

   seg[no] = mergeNodes(esq, dir);
}

int rangeQuery(int no, int l, int r, int lo, int hi) {
   if (l > hi || r < lo) return 0;
   if (l >= lo && r <= hi) return seg[no];

   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   return rangeQuery(esq, l, mid, lo, hi) + rangeQuery(dir, mid + 1, r, lo, hi);
}
int main(){
	scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d%d", &n, &q);
      for (int i = 0; i < n; i++)
         scanf("%d", a + i);
      build(1, 0, n - 1);
      
      printf("Case %d:\n", t);
      for (int k = 0; k < q; k++) {
         int type;
         scanf("%d", &type);

         if (type == 1) {
            int i;
            scanf("%d", &i);
            printf("%d\n", a[i]);
            pointUpdate(1, 0, n - 1, i, 0);
         }
         if (type == 2) {
            int v, i;
            scanf("%d%d", &i, &v);
            pointUpdate(1, 0, n - 1, i, a[i] + v);
         }
         if (type == 3) {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%d\n", rangeQuery(1, 0, n - 1, i, j));
         }
      }
   }
   return 0;
} 
