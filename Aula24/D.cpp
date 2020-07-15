//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, raiz;
int p[MAX], m[MAX];
vector<int> adj[MAX];
vector<int> ans;

bool seen[MAX];
int sum[MAX], total;

int dfs (int u, int que) {
    sum[u] = m[u];
    for (int v : adj[u]) {
	sum[u] += dfs(v, que);
    }
    if (sum[u] == que && u != raiz) {
	ans.pb(u);
	return 0;
    }
    return sum[u];
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
	int a, t;
	cin >> a >> t;
	if (a == 0) {
	    raiz = i;
	} else {
	    adj[a].pb(i);
	}
	
	m[i] = t;
	total += t;
    }
    if (total % 3 != 0) {
	cout << -1 << '\n';
	return 0;
    }
    dfs(raiz, total/3);
    if (ans.size() >= 2) {
	for (int i = 0; i < 2; i++)
	    cout << ans[i] << ' ';
	cout << '\n';
	return 0;
    }

    cout << -1 << '\n';
    return 0;
}
