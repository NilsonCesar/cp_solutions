#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, num, ans = 0;
    cin >> n >> x;
    map<long long, int> count;
    count[0] = 1;
    long long sumpref = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        sumpref += num;
        ans += count[sumpref - x];
        count[sumpref]++;
    }
    
    cout << ans << '\n';

    return 0;
}
