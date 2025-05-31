#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int t;
    cin >> t;
    while(t--) {
        int n, n_1 = 0, n_max = 0, n_max_i = 0, cur = 0, ans = 0;
        cin >> n;
        string s;
        cin >> s;
        s = s + '0';
        vector<vector<int>> ones;
        bool interval = false;

        for (int i = 0; i <= n; i++) {
            if (s[i] == '1' && !interval) {
                interval = true;
                ones.push_back({i, i});   
            } else if (s[i] == '1') {
                ones[cur][1]++;
            } else if (interval) {
                interval = false;
                n_1 += ones[cur][1] - ones[cur][0] + 1;
                if (n_max < ones[cur][1] - ones[cur][0] + 1) {
                    n_max_i = cur;
                    n_max = ones[cur][1] - ones[cur][0] + 1;
                }
                cur++;
            }
        }

        int m = (int) ones.size();

        int l = n_max_i - 1, r = n_max_i + 1, ld = n_max_i, rd = n_max_i;

        while (l >= 0 || r < m) {
            if (l >= 0) {
                int ones_len = ones[l][1] - ones[l][0] + 1;
                int ones_gap = ones[ld][0] - ones[l][1] - 1;
                if (ones_len > ones_gap) {
                    for (int j = ld - 1; j >= l; j--) {
                        int ones_gap_j = ones[ld][0] - ones[j][1] - 1;
                        int ones_len_j = ones[j][1] - ones[j][0] + 1;
                        ans += ones_gap_j - ones_len_j;
                        ld = j;
                    }
                } else ans += ones_len;
                l--;
            }

            if (r < m) {
                int ones_len = ones[r][1] - ones[r][0] + 1;
                int ones_gap = ones[r][0] - ones[rd][1] - 1;
                if (ones_len > ones_gap) {
                    for (int j = rd + 1; j <= r; j++) {
                        int ones_len_j = ones[j][1] - ones[j][0] + 1;
                        int ones_gap_j = ones[j][0] - ones[rd][1] - 1;
                        rd = j;
                        ans += ones_gap_j - ones_len_j;
                    }
                }
                else ans += ones_len;
                r++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}