#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000100

int id[MAXN], sz[MAXN];
int n;

int root(int p) {
    if(id[p] == p) return p;
    return id[p] = root(id[p]);
}

void union_uf(int p, int q) {
    int i = root(p);
    int j = root(q);

    if(i == j) return;
    if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

bool connected(int p, int q) { return root(p) == root(q); }

void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int n, q, x, y;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while(q--) {
        cin >> x >> y;

        int ans = 0;
        int cur_v = root(1);

        while(cur_v <= x) {
            ans += sz[cur_v];
            sz[y] += sz[cur_v];
            sz[cur_v] = 0;
            int parent = root(cur_v + 1);
            id[cur_v] = id[parent]; 
            cur_v = root(parent);
        }

        cout << ans << '\n';
    }


    return 0;
}
