#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 998244353

int main(void) {_
    string s;
    cin >> s;
    
    map<char, long long> dp;

    for (char n : s) {
        dp[n] = (dp['a'] + dp['b'] + dp['c'] + 1) % MOD;
    }

    cout << (((dp['a'] + dp['b']) % MOD) + dp['c']) % MOD << '\n';

    return 0;
}
