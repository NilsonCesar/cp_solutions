#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define MAX 1000010
#define INF 100000000

int v[MAX];
int seg[4*MAX];

int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

int query(int a, int b, int p, int l, int r) {
    if (b < l or r < a) return 0;
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
}


int main(void) {
    mainIO();
    int n, q, x, y;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        v[i] = 1;
    build(1, 0, n - 1);

    while(q--) {
        cin >> x >> y;
        cout << query(0, x - 1, 1, 0, n - 1) << '\n';

        update(y - 1, v[y - 1] + query(0, x - 1, 1, 0, n - 1), 1, 0, n -1);
        for (int i = 0; i < x; i++) {
            update(i, 0, 1, 0, n - 1);
        }
    }

    return 0;
}
