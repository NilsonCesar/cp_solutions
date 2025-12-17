#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MAXQ 100007

vector<pair<int, int>> l[MAXN], vq[MAXN];
int n, q;

int resp[MAXQ];
int cnt[MAXN], id[MAXN], dist[MAXN];

void update(int u, int v) {
    cnt[id[u]]--;
    id[u] = v;
    cnt[id[u]]++;
}

void pre_calc(int u, int p) {
    pair<int, int> filho_min = {INF, 0};
    for (auto e : l[u]) {
        if (e.first != p) {
            pre_calc(e.first, u);
            filho_min = min(filho_min, {e.second + dist[e.first], id[e.first]});
        }
    }

    if (l[u].size() > 1) {
        dist[u] = filho_min.first;
        id[u] = filho_min.second;
    } else {
        dist[u] = 0;
        id[u] = u;
    }

    cnt[id[u]]++;
}

void dfs_calc(int u, int p) {
    for (auto qr: vq[u]) {
        resp[qr.second] = cnt[qr.first];
    }

    pair<int, int> filho_min = {INF, 0};
    for (auto e : l[u]) {
        if (id[e.first] != id[u]) {
            filho_min = min(filho_min, {e.second + dist[e.first], id[e.first]});
        }
    }

    int u_old_id = id[u], old_dist = dist[u];
    for (auto e : l[u]) {
        if (e.first != p) {
            int e_id = id[e.first], e_dist = dist[e.first];
            if (id[e.first] != id[u]) {
                if (make_pair(dist[u] + e.second, id[u]) < make_pair(dist[e.first], id[e.first])) {
                    update(e.first, id[u]);
                    dist[e.first] = dist[u] + e.second;
                } 
            } else {
                update(u, filho_min.second);
                dist[u] = filho_min.first;
            }
            dfs_calc(e.first, u);
            update(u, u_old_id);
            dist[u] = old_dist;
            update(e.first, e_id);
            dist[e.first] = e_dist;
        }
    }
}

int main(void) {_

    cin >> n;

    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        l[a].push_back({b, c});
        l[b].push_back({a, c});
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        vq[b].push_back({a, i});
    }

    pre_calc(1, 0);
    dfs_calc(1, 0);

    for (int i = 0; i < q; i++) {
        cout << resp[i] << '\n';
    }

    return 0;
}
