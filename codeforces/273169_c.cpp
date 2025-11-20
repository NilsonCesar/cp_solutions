#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

vector<int> v(MAXN, 0);
vector<pair<int, int>> seg(MAXN*4, {0, 0});

pair<int, int> minPair(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return a;
    if (a.first == b.first) return {a.first, a.second + b.second};
    return b; 
}

pair<int, int> build(int p, int l, int r) {
    if (l == r) {
        seg[p].second++;
        seg[p].first = v[l];
        return seg[p];
    }
    int m = (l + r) / 2;
    return seg[p] = minPair(build(2 * p, l, m), build(2 * p + 1, m + 1, r));  
}

pair<int, int> query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return {INF, 0};
    if (a <= l && r <= b) return seg[p];
    int m = (l + r) / 2;
    return minPair(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

pair<int, int> update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) {
        seg[p].first = x;
        seg[p].second = 1;
        return seg[p];
    }
    int m = (l + r) / 2;
    return seg[p] = minPair(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

int main(void) {_
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    build(1, 0, n - 1);
    int op, l, r;

    while(m--) {
        cin >> op >> l >> r;
        if (op == 1) {
            update(l, r, 1, 0, n - 1);
        } else {
            pair<int, int> ans = query(l, r - 1, 1, 0, n - 1);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }

    return 0;
}
