#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 1000000007

int main(void) {_
    int t, l, r; 
    cin >> t;
    vector<long long> sumpref(MAXN, 0), pow_of_2(MAXN, 1);

    for (int i = 1; i <= 1e5; i++) {
        pow_of_2[i] = (pow_of_2[i - 1] * 2) % MOD;
        sumpref[i] = (MOD + sumpref[i - 1] + (((pow_of_2[i - 1]) % MOD) - ((pow_of_2[i / 2]) % MOD) + MOD) % MOD) % MOD;
    }

    while(t--) {
        cin >> l >> r;
        cout << ((sumpref[r] - sumpref[l - 1] + MOD) % MOD) << '\n';
    }

    return 0;
}
