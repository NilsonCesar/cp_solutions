#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 1e5+7

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

string s, t;
set<char> cs;
map<char, int> c_to_i;
long dist[200][200];

vector<int> dijskstra(vector<vector<pair<int, int>>> &g, int source) {
    priority_queue<pair<int, int>> pq;
    pq.push({-0, source});
    vector<int> distw((int) g.size(), INF);
    while(!pq.empty()) {
        long node = pq.top().second, w = -pq.top().first;
        pq.pop();
        if (distw[node] <= w) continue;
        distw[node] = w;
        for (pair<int, int> p: g[node]) {
            long u = p.first, d = p.second;
            if (d + w < distw[u]) {
                pq.push({-(d + w), u});
            } 
        }
    }

    return distw;
}

int main(void) {
    mainIO();
    cin >> s >> t;
    for (char c : s + t)
        cs.insert(c);
    int label = 0;
        
    int m, w;
    char a, b;
    cin >> m;
    vector<char> tmp1, tmp2;
    vector<int> weights;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        cs.insert(a);
        cs.insert(b);
        tmp1.push_back(a), tmp2.push_back(b), weights.push_back(w);
    }
    
    for (char c : cs) c_to_i[c] = label++;
    vector<vector<pair<int, int>>> g((int) cs.size(), vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        a = tmp1[i], b = tmp2[i], w = weights[i];
        g[c_to_i[a]].push_back({c_to_i[b], w});
    }

    for (char c: cs) {
        int i = c_to_i[c];
        vector<int> distd = dijskstra(g, i);

        for (char cc: cs) {
            int j = c_to_i[cc];
            dist[i][j] = distd[j];
        }
    }


    int n = (int) s.size();
    long ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        int si = c_to_i[s[i]], ti = c_to_i[t[i]];
        long d = dist[si][ti];
        // cout << s[i] << "--> " << t[i] << ": " << d << '\n';
        if (d == INF) {
            cout << -1 << '\n';
            return 0;
        }
        ans += d;
    }

    cout << ans << '\n';

    return 0;
}
