#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

vector<int> a;
vector<vector<int>> st;
map<int, int> height_to_idx;

int query(int l, int r) {
    int len = r - l + 1;
    if (len == 0) return -1;
    int k = (int) log2(len);
    return height_to_idx[max(st[l][k], st[r + 1 - (1 << k)][k])];
}

long long solve(int i, int j, int k) {
    if (i > j) return 0;
    int i1 = query(i, k - 1);
    int i2 = query(k + 1, j);
    long long ans = 0;
    if (i1 != -1) ans = abs(i1 - k) + solve(i, k - 1, i1);
    if (i2 != -1) ans = max(ans, abs(i2 - k) + solve(k + 1, j, i2));
    return ans; 
}

int main(void) {_
    int n;
    cin >> n;
    a.resize(n);
    int k = 0;
    st.resize(n + 7, vector<int>(((int) log2(n)) + 7));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[i][0] = a[i];
        if (a[i] > a[k]) k = i;
        height_to_idx[a[i]] = i;
    }

    for (int j = 1; 1 << j <= n; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    // query = max(st[L][k], st[R + 1 - (1 << k)][k]);
    cout << solve(0, n - 1, k) << '\n';

    return 0;
}
