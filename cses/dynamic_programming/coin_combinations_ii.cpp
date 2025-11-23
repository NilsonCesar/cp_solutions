#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 1000007

long long memo[MAXN], c[MAXN];

int main(void) {_
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];

    memo[0] = 1;
    sort(c, c + n);
    for (int i = 0; i < n; i++) {
        for (int s = 1; s <= x; s++) {
            if (s - c[i] < 0) continue;
                memo[s] += (memo[s - c[i]] % (1000000000+7));
        }
    }

    cout << memo[x] % (1000000000+7) << '\n';

    return 0;
}
