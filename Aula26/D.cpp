#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args);

typedef long long int ll;

const int MAX = 2e5 + 10;

int n, m, cur, iden[MAX];

struct node {
   int id, pai, sz, activeSz;
   ll sum;
   node(int ID = 0, int P = 0, int S = 0, ll SM = 0, int A = 0):
      id(ID), pai(P), sz(S), sum(SM), activeSz(A) {}
};

node v[MAX];

int raiz(node& x) {
   if (x.pai == x.id) return x.id;

   return x.pai = raiz(v[x.pai]);
}

void une(int IDA, int IDB) {
   int raizIDA = raiz(v[IDA]);
   int raizIDB = raiz(v[IDB]);
   
   if (v[raizIDA].id == v[raizIDB].id) return;
   if (v[raizIDB].sz > v[raizIDA].sz) swap(raizIDA, raizIDB);
   
   v[raizIDB].pai = v[raizIDA].id;
   v[raizIDA].sz += v[raizIDB].sz;
   v[raizIDA].sum += v[raizIDB].sum;
   v[raizIDA].activeSz += v[raizIDB].activeSz;
}

void moveNode(int IDA, int IDB, int num) {
   int raizIDA = raiz(v[IDA]);
   int raizIDB = raiz(v[IDB]);

   if (v[raizIDA].id == v[raizIDB].id) return;

   v[raizIDA].sum -= num;
   v[raizIDA].activeSz--;

   iden[num] = cur;
   v[cur] = node(cur, v[raizIDB].id, 1, num, 1);
   v[raizIDB].sum += num;
   v[raizIDB].sz++;
   v[raizIDB].activeSz++;
   cur++;
}
int main() {
   while (scanf("%d%d", &n, &m) != EOF) {
      cur = n + 1;
      for (int i = 1; i <= n; i++) {
         v[i] = node(i, i, 1, i, 1);
         iden[i] = i;
      }
      
      for (int i = 0; i < m; i++) {
         int op, p, q;
         scanf("%d", &op);
         if (op == 1) {
            scanf("%d%d", &p, &q);
            une(iden[p], iden[q]);
         } else if (op == 2) {
            scanf("%d%d", &p, &q);
            moveNode(iden[p], iden[q], p);
         } else if (op == 3) {
            scanf("%d", &p);
            int r = raiz(v[iden[p]]);
            printf("%d %lld\n", v[r].activeSz, v[r].sum);
         }

      }
      memset(v, 0, sizeof(v));
      memset(iden, 0, sizeof(iden));
   }
   return 0;
}
