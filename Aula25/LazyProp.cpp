#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int n, q, T;
int seg[4 * MAX];
int lazy[4 * MAX];
int a[MAX];

int mergeNodes(int esq, int dir) {
   return seg[esq] + seg[dir];
}

void build(int no, int l, int r) {
   if (l == r) {
      seg[no] = a[l];
      lazy[no] = 0;
      return;
   }

   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   build(esq, l, mid);
   build(dir, mid + 1, r);

   seg[no] = mergeNodes(esq, dir);
}

void propLazy(int no, int l, int r) {
   if (lazy[no] != 0) {
      seg[no] += (r - l + 1) * lazy[no];
      
      if (l != r) {
         int esq = 2 * no;
         int dir = 2 * no + 1;
         lazy[esq] += lazy[no];
         lazy[dir] += lazy[no];
      }
      
      lazy[no] = 0;
   }
}

// Soma no intervalo lo-hi
void rangeUpdate(int no, int l, int r, int lo, int hi, int val) {
   if (l > hi || r < lo) return;
   propLazy(no, l, r);

   if (l >= lo && r <= hi) {
      lazy[no] += val;
      return;
   }
   
   int esq = 2 * no;
   int dir = 2 * no + 1;
   int mid = (l + r) / 2;

   rangeUpdate(esq, l, mid, lo, hi, val);
   rangeUpdate(dir, mid + 1, r, lo, hi, val);   
}

int rangeQuery(int no, int l, int r, int lo, int hi) {
   propLazy(no, l, r);

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

         if (type == 2) {
            int v, i, j;
            scanf("%d%d%d", &i, &j, &v);
            rangeUpdate(1, 0, n - 1, i, j, v);
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
