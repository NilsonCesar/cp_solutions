#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

struct Repr {
    long long x, y;
    int count;
    int original_id;
    long double angle;
};

pair<long long, long long> normalize(long long x, long long y) {
    long long g = gcd(abs(x), abs(y));
    return {x / g, y / g};
}

bool sort_by_angle(Repr a, Repr b) {
    return a.angle > b.angle;
}

int main(void) {_
    int n, q, a, b;
    cin >> n >> q;

    vector<pair<long long, long long>> monsters(n + 1);
    map<pair<long long, long long>, int> repr_map;
    vector<Repr> reprs;

    for (int i = 1; i <= n; i++) {
        cin >> monsters[i].first >> monsters[i].second;
        pair<long long, long long> norm = normalize(monsters[i].first, monsters[i].second);

        if (repr_map.find(norm) == repr_map.end()) {
            repr_map[norm] = reprs.size();
            reprs.push_back({norm.first, norm.second, 0, 0, atan2l(norm.second, norm.first)});
        }
        reprs[repr_map[norm]].count++;
    }

    sort(reprs.begin(), reprs.end(), sort_by_angle);

    vector<int> monster_to_id(n + 1);
    map<pair<long long, long long>, int> sorted_repr_map;
    for (int i = 0; i < reprs.size(); i++) {
        sorted_repr_map[{reprs[i].x, reprs[i].y}] = i;
    }

    for (int i = 1; i <= n; i++) {
        pair<long long, long long> norm = normalize(monsters[i].first, monsters[i].second);
        monster_to_id[i] = sorted_repr_map[norm];
    }

    int r = reprs.size();
    vector<long long> prefix(r);
    prefix[0] = reprs[0].count;
    for (int i = 1; i < r; i++) {
        prefix[i] = prefix[i - 1] + reprs[i].count;
    }

    while(q--) {
        cin >> a >> b;
        int u = monster_to_id[a];
        int v = monster_to_id[b];

        if (u <= v) {
            long long sv = prefix[v];
            long long su = (u == 0 ? 0 : prefix[u - 1]);
            cout << sv - su;
        } else {
            long long sv = prefix[v];
            long long su = prefix[r - 1] - (u == 0 ? 0 : prefix[u - 1]);
            cout << sv + su;
        }
        cout << '\n';
    }

    return 0;
}
