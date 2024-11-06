#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1e10

using namespace std;

long long v[MAXN], seg[4 * MAXN];

long long build(int p, int l, int r) {
    if(l == r) return seg[p] = v[l];
    int m = (l + r) / 2; 
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

long long query(int a, int b, int p, int l, int r) {
    if(b < l or r < a) return INF;
    if(a <= l and r <= b) return seg[p];
    int m = (l + r) / 2;
    return min(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

long long update(int i, int x, int p, int l, int r) {
    if(i < l or r < i) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l + r) / 2;
    return seg[p] = min(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);
    
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(a == 1) 
            update(b, c, 1, 0, n - 1);
        else
            cout << query(b, c - 1, 1, 0, n - 1) << '\n';
    }
    return 0;
}
