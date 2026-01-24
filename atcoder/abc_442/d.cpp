#include <bits/stdc++.h>

using namespace std;
#define MAXN 200007
#define INF 0x3f3f3f3f

long long v[MAXN];
long long seg[MAXN*4];

// p = seg index, l = left end in v, r = right end in v (inclusive)
// build(1, 0, n - 1);
long long build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l + r) / 2;
    return seg[p] = (build(2 * p, l, m) + build(2 * p + 1, m + 1, r));  
}

// query(l, r, 1, 0, n - 1);
long long query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return seg[p];
    int m = (l + r) / 2;
    return (query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r));
}

// update(i, x, 1, 0, n - 1); muda valor da posicao i para x
long long update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l + r) / 2;
    return seg[p] = (update(i, x, 2 * p, l, m) + update(i, x, 2 * p + 1, m + 1, r));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q, op, l, r;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    while(q--) {
        cin >> op;
        if (op == 2) {
            cin >> l >> r;
            cout << query(l - 1, r - 1, 1, 0, n - 1) << '\n';
        } else {
            cin >> l;
            update(l - 1, v[l], 1, 0, n - 1);
            update(l, v[l - 1], 1, 0, n - 1);
            swap(v[l - 1], v[l]);
        }
    }
}