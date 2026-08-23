#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO("diamond");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int r = 0;
    vector<int> left_size(n, n - 1), max_right(n, 0);

    for (int l = 0; l < n; l++) {
        while(r < n && a[r] - a[l] <= k) r++;
        left_size[l] = r - l;
    }

    max_right[n - 1] = left_size[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        max_right[i] = max(max_right[i + 1], left_size[i]);
    }

    for (int i = 0; i < n; i++) {
        int next_idx = i + left_size[i];
        ans = max(ans, left_size[i] + max_right[next_idx]);
    }

    cout << ans << '\n';

    return 0;
}
