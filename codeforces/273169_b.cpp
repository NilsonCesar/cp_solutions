#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100000+7

int v[MAXN], seg[4 * MAXN], n, m;

int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l + r) / 2;
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

int query(int a, int b, int p, int l, int r) {
    if (b < l || a > r) return INF;
    if (a <= l && r <= b) return seg[p];
    int m = (l + r) / 2;
    return min(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r)); 
}

int update(int i, int x, int p, int l, int r) {
    if (i < l || i > r) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l + r) / 2;
    return seg[p] = min(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

int main(void) {_
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);
    
    int op, i, x;
    while(m--) {
        cin >> op >> i >> x;

        if (op == 1) update(i, x, 1, 0, n - 1);
        else cout << query(i, x - 1, 1, 0, n - 1) << '\n';
    }

    return 0;
}
