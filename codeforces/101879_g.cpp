#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 2000000010
#define MAXN 200007


int vMin[MAXN], vMax[MAXN];
int segMin[MAXN*4], segMax[MAXN*4];

int buildMin(int p, int l, int r) {
    if (l == r) return segMin[p] = vMin[l];
    int m = (l + r) / 2;
    return segMin[p] = min(buildMin(2 * p, l, m), buildMin(2 * p + 1, m + 1, r));  
}

int queryMin(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return INF;
    if (a <= l && r <= b) return segMin[p];
    int m = (l + r) / 2;
    return min(queryMin(a, b, 2 * p, l, m), queryMin(a, b, 2 * p + 1, m + 1, r));
}

int updateMin(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return segMin[p];
    if (l == r) return segMin[p] = x;
    int m = (l + r) / 2;
    return segMin[p] = min(updateMin(i, x, 2 * p, l, m), updateMin(i, x, 2 * p + 1, m + 1, r));
}

int buildMax(int p, int l, int r) {
    if (l == r) return segMax[p] = vMax[l];
    int m = (l + r) / 2;
    return segMax[p] = max(buildMax(2 * p, l, m), buildMax(2 * p + 1, m + 1, r));  
}

int queryMax(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return -INF;
    if (a <= l && r <= b) return segMax[p];
    int m = (l + r) / 2;
    return max(queryMax(a, b, 2 * p, l, m), queryMax(a, b, 2 * p + 1, m + 1, r));
}

int updateMax(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return segMax[p];
    if (l == r) return segMax[p] = x;
    int m = (l + r) / 2;
    return segMax[p] = max(updateMax(i, x, 2 * p, l, m), updateMax(i, x, 2 * p + 1, m + 1, r));
}

int main(void) {_
    int n, q, l, r, i;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        vMax[i] = l;
        vMin[i] = r; 
    }

    buildMin(1, 0, n - 1);
    buildMax(1, 0, n - 1);

    char op;

    while(q--) {
        cin >> op;

        if (op == '?') {
            cin >> l >> r; l--, r--;
            int ans = queryMin(l, r, 1, 0, n - 1) - queryMax(l, r, 1, 0, n - 1) + 1;
            cout << (ans >= 0 ? ans : 0) << '\n';
        } else {
            cin >> i >> l >> r; i--;
            updateMax(i, l, 1, 0, n - 1);
            updateMin(i, r, 1, 0, n - 1);
        }
    }

    return 0;
}
