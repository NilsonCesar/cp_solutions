#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vector<int> id, sz;
int n;

int root(int p) {
    if(id[p] == p) return p;
    return id[p] = root(id[p]);
}


void uf_union(int p, int q) {
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


int main(void) {
    mainIO();
    int n, m, m_temp;
    unsigned long long ans = 0;
    cin >> n >> m;
    vector<pair<int, int>> x(n);
    vector<int> xx(n);
    m_temp = n;
    id.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++) {
        id[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
        xx[i] = x[i].first;
    }
    sort(x.begin(), x.end());
    priority_queue<vector<int>> dists;
    for (int i = 1; i < n - 1; i++) {
        dists.push({-abs(x[i].first - x[i - 1].first), x[i - 1].second, x[i].second});
        dists.push({-abs(x[i + 1].first - x[i].first), x[i].second, x[i + 1].second});
    }
    while (m_temp > m) {
        vector<int> dist = dists.top();
        dists.pop();
        if(connected(dist[1], dist[2])) continue;
        m_temp--;
        uf_union(dist[1], dist[2]);
    }

    map<int, vector<unsigned long long>> max_min;
    set<int> already;

    for (int i = 0; i < n; i++) {
        if (already.find(id[i]) != already.end()) continue;
        max_min[id[i]] = vector<unsigned long long>(2);
        max_min[id[i]][0] = 1e14;
        max_min[id[i]][1] = 0;
        already.insert(id[i]);
    }
    for (int i = 0; i < n; i++) {
        max_min[id[i]][0] = min(max_min[id[i]][0], (unsigned long long) xx[i]);
        max_min[id[i]][1] = max(max_min[id[i]][1], (unsigned long long) xx[i]);
    }

    for (int id : already) {
        // cout << id << ' ' << max_min[id][0] << ' ' << max_min[id][1] << '\n';
        ans += max_min[id][1] - max_min[id][0];
    }
    
    cout << ans << '\n';

    return 0;
}
