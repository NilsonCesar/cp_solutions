#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 998244353

int main(void) {_
    string s;
    cin >> s;
    int n = (int) s.size();

    long long ans = 1;
    int i = 0, j = 1;

    while(j < n) {
        if (s[j - 1] == s[j]) {
            i = j;
            ans = (ans + 1) % MOD;
        } else {
            ans = (ans + j - i + 1) % MOD;
        }
        j++;
    }

    cout << ans << '\n';

    return 0;
}
