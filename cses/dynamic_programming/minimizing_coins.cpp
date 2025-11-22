#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 1000007

long long n, x;
long long memo[MAXN], c[MAXN];

int main(void) {_
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < MAXN; i++) memo[i] = INF;
    sort(c, c + n);
    long long ans;
    memo[0] = 0;
    for (long long s = 1; s <= x; s++) {
        ans = INF;
        for (int i = 0; i < n; i++)
            if (c[i] <= s)
                ans = min(ans, 1 + memo[s - c[i]]);
        memo[s] = ans;
    }
    cout << (memo[x] == INF ? -1 : memo[x]) << '\n';

    return 0;
}
