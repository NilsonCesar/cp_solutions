#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, m, l, r;
    cin >> n >> m;

    vector<long long> start_freq(m + 7, 0), end_freq(m + 7, 0);

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        start_freq[l]++;
        end_freq[r]++;
    }

    vector<long long> start_pairs(2 * m + 7, 0), end_pairs(2 * m + 7, 0);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            start_pairs[i + j] += start_freq[i] * start_freq[j];
            end_pairs[i + j] += end_freq[i] * end_freq[j];
        }
    }

    long long ans = 0;    
    for (int k = 0; k <= 2 * m; k++) {
        ans += start_pairs[k];
        cout << ans << '\n';
        ans -= end_pairs[k];
    }

    return 0;
}
