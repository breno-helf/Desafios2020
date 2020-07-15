#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;

int n, t, u, q;
int seg[4 * MAX];

void build(int no, int l, int r) {
   
}

int main(){
	scanf("%d", &t);
	for (int g = 0; g < t; g++) {
		scanf("%d%d", &n, &u);
		for (int i = 0; i < u; i++) {
         int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
         int ind;
         scanf("%d", &ind);
			printf("%d\n", query(ind + 1));
		}
	}
	return 0;
} 
