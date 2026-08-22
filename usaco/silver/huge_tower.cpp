#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 1000000009

int main(void) {_
    int n, d;
    cin >> n >> d;
    vector<int> blocks(n);
    for (int i = 0; i < n; i++)
        cin >> blocks[i];
    sort(blocks.begin(), blocks.end());
    long long ans = 1;
    long long l = 0;

    for (long long i = 0; i < n; i++) {
        while (blocks[i] > blocks[l] + d) l++;
        ans = (ans * ((i - l) + 1)) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
