#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007
#define MOD 1000000007

int main(void) {_
    int n, a;
    cin >> n;
    set<int> nums;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.insert(a);
        freq[a]++;
    }

    long long ans = 1;
    for (int num: nums) {
        ans = (ans * (freq[num] + 1) % MOD);
    }
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << '\n';

    return 0;
}
