#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int binary_search(vector<vector<long long>>& stores, long long value) {
    int l = 1, r = (int) stores.size() - 1, ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (value <= stores[mid][0] && value >= stores[mid - 1][0]) {
            ans = mid;
            r = mid - 1;
        } else if (value < stores[mid][0]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO("rental");
    int n, m, r;
    cin >> n >> m >> r;
    vector<long long> cows(n + 1), neighbors(r + 1);
    vector<vector<long long>> stores(m + 1, vector<long long>(4, 0));
    vector<long long> sumpref_cows(n + 1, 0), sumpref_neighbors(r + 1, 0);

    for (int i = 1; i <= n; i++) cin >> cows[i];
    for (int i = 1; i <= m; i++) cin >> stores[i][1] >> stores[i][0];
    for (int i = 1; i <= r; i++) cin >> neighbors[i];

    sort(cows.begin(), cows.end());
    sort(stores.begin() + 1, stores.end(), greater<vector<long long>>());
    sort(neighbors.begin() + 1, neighbors.end(), greater<long long>());

    for (int i = 1; i <= m; i++) {
        swap(stores[i][0], stores[i][1]);
        stores[i][2] = stores[i][0];
        stores[i][3] = stores[i][0] * stores[i][1] + stores[i - 1][3];
        stores[i][0] += stores[i - 1][0];
    }

    for (int i = 1; i <= n; i++) {
        sumpref_cows[i] = sumpref_cows[i - 1] + cows[i];
    }

    for (int i = 1; i <= r; i++) {
        sumpref_neighbors[i] = sumpref_neighbors[i - 1] + neighbors[i];
    }
    
    int ans_i;
    long long ans = 0;

    for (int i = 0; i <= min(r, n); i++) {
        long long tmp_ans = sumpref_neighbors[i];
        long long remainder_cows = sumpref_cows[n] - sumpref_cows[i];
        ans_i = binary_search(stores, min(remainder_cows, stores[m][0]));
        tmp_ans += stores[ans_i - 1][3] + min(stores[ans_i][2] ,remainder_cows - stores[ans_i - 1][0]) * stores[ans_i][1];

        ans = max(ans, tmp_ans);
    }

    cout << ans << '\n';

    return 0;
}
