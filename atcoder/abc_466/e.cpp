#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 200007

int n, k;
vector<long long> ans(11, 0);
vector<vector<long long>> nums(MAXN, vector<long long>(2));

void solve(int i, vector<int>& flips) {
    if (ans[i]) return;

    if (i <= k) {
        long long tmp_ans = 0, max_ans = -1;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                tmp_ans = 0;
                for (int j = l; j <= r; j++)
                    flips[j] = !flips[j];
                for (int j = 1; j <= n; j++)
                    tmp_ans += nums[j][flips[j]];
                max_ans = max(max_ans, tmp_ans);
                solve(i + 1, flips);
                for (int j = l; j <= r; j++)
                    flips[j] = !flips[j];
            }
        }
        ans[i] = max(ans[i], max_ans);
    }
}

int main(void) {_
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    vector<int> flips(MAXN, 0);

    solve(1, flips);
    long long ans_i = -1;

    for (int i = 1; i <= k; i++) ans_i = max(ans_i, ans[i]);

    cout << ans_i << '\n';

    return 0;
}
