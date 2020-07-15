#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int n, q, T;
int seg[4 * MAX];
int a[MAX];

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
   
   seg[no] = seg[esq] + seg[dir];   
}

void update(int no, int l, int r, int pos, int val) {
   if (l == r) {
      seg[no] = val;
      a[l] = val;
      return;
   }

   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   if (pos <= mid)
      update(esq, l, mid, pos, val);
   else
      update(dir, mid + 1, r, pos, val);

   seg[no] = seg[esq] + seg[dir];
}

int query(int no, int l, int r, int lo, int hi) {
   if (l > hi || r < lo) return 0;
   if (l >= lo && r <= hi) return seg[no];

   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   return query(esq, l, mid, lo, hi) + query(dir, mid + 1, r, lo, hi);
}

int main(){
	scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d%d", &n, &q);
      for (int i = 1; i <= n; i++)
         scanf("%d", a + i);

      build(1, 1, n);
      printf("Case %d:\n", t);
      for (int k = 0; k < q; k++) {
         int type;
         scanf("%d", &type);

         if (type == 1) {
            int i;
            scanf("%d", &i);
            i++;
            printf("%d\n", a[i]);
            a[i] = 0;
            update(1, 1, n, i, 0);
         }
         if (type == 2) {
            int v, i;
            scanf("%d%d", &i, &v);
            i++;
            a[i] += v;
            update(1, 1, n, i, a[i]);
         }
         if (type == 3) {
            int i, j;
            scanf("%d%d", &i, &j);
            i++;j++;
            printf("%d\n", query(1, 1, n, i, j));
         }
      }
   }
   return 0;
} 
