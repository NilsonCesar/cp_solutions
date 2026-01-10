#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

void solve() {
    int n, w;
    cin >> n >> w;
    vector<long long> c(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        total_sum += c[i];
    }

    vector<long long> blocks(2 * w, 0);
    for (int i = 0; i < n; i++) {
        blocks[(i + 1) % (2 * w)] += c[i];
    }

    vector<long long> cycle_block(4 * w, 0);
    for (int i = 0; i < 4 * w; i++) {
        cycle_block[i] = blocks[i % (2 * w)];
    }

    long long current_white_sum = 0;
    for (int i = 0; i < w; i++) current_white_sum += cycle_block[i];
    long long max_white_sum = current_white_sum;

    for (int i = w; i < 3 * w; ++i) {
        current_white_sum += cycle_block[i] - cycle_block[i - w];
        max_white_sum = max(max_white_sum, current_white_sum);
    }

    cout << total_sum - max_white_sum << '\n';
}

int main(void) {_
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
