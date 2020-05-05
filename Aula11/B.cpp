#include<bits/stdc++.h>
using namespace std;

struct circle {
   int x, y, r;
   circle(int X = 0, int Y = 0, int R = 0):
      x(X), y(Y), r(R) {};

   bool operator == (const circle ot) const {
      return (x == ot.x && y == ot.y && r == ot.r);      
   }
};


vector<circle> V;

bool overlap(circle C1, circle C2) {
   int dist = (C1.x - C2.x) * (C1.x - C2.x) + (C1.y - C2.y) * (C1.y - C2.y);
   int radius = (C1.r + C2.r) * (C1.r + C2.r);
   //cerr << dist << " " << radius << endl;
   return radius <= dist;
}

int main() {
   int q;
   cin >> q;

   while (q--) {
      char op;
      int x, y, r;
      cin >> op >> x >> y >> r;
      circle c = circle(x, y, r);
      
      if (op == 'A') {
         bool ok = true;

         for (circle ot : V) {
            ok &= overlap(c, ot);
         }

         if (ok) {
            puts("Ok");
            V.push_back(c);
         } else {
            puts("No");
         }
      } else {
         // C++11
         // vector<circle>::iterator it = find(V.begin(), V.end(), c);
         auto it = find(V.begin(), V.end(), c);
         if (it == V.end()) {
            puts("No");
         } else {
            V.erase(it);
            puts("Ok");
         }
      }
      
   }
}
