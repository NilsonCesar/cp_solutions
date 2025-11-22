#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 1000007

long long memo[MAXN];
int n;
long long solve(int sum) {
    if (sum == 0 || sum == 1) return 1;
    if (memo[sum]) return memo[sum];

    for (int i = 1; i <= 6; i++) {
        if (sum - i >= 0) {
            memo[sum] += (solve(sum - i) % (1000000000 + 7));
        }
    }

    return memo[sum] % (1000000000 + 7);
}

int main(void) {_
    cin >> n;
    cout << solve(n) << '\n';

    return 0;
}
