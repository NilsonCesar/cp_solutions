#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 1001000

int n, m;
vector<int> g[MAXN];
int pai[MAXN];
bool visited[MAXN];


void dfs(int i) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto u: g[i])
        if (!visited[u]) {
            pai[u] = i; 
            dfs(u);
        }
}

int main(void) {_
    cin >> n >> m;

    int q, k;
    for (int i = 1; i <= n; i++) {
        cin >> q;
        for (int j = 0; j < q; j++) {
            cin >> k;
            g[m + i].push_back(k);
            g[k].push_back(m + i);
        }
    }

    for (int i = 1; i <= n + m; i++) {
        if (visited[i]) continue;
        pai[i] = -1;
        dfs(i);
    }

    cin >> q;

    int x, y;
    vector<int> px, py;

    while(q--) {
        cin >> x >> y;
        px.clear();
        py.clear();
        for (int a = x; a != -1; a = pai[a]) {
            px.push_back(a);
        }

        for (int a = y; a != -1; a = pai[a]) {
            py.push_back(a);
        }

        if (px.back() != py.back()) {
            cout << -1 << '\n';
            continue;
        }

        while(px.size() > 1 && py.size() > 1 && px[px.size() - 2] == py[py.size() - 2]) {
            px.pop_back();
            py.pop_back();
        }

        cout << (px.size() + py.size()) / 2 << '\n';

        for (int i = 0; i < px.size(); i++)
            cout << (px[i] > m ? px[i] - m : px[i]) << ' ';
        for (int i = py.size() - 2; i >= 0; i--)
            cout << (py[i] > m ? py[i] - m : py[i]) << ' ';
        cout << '\n';
    }

    return 0;
}
