#include <bits/stdc++.h>

using namespace std;

set<int> ans;
set<int> divisors(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.insert(i);
            ans.insert(n / i);
        }
    }
    ans.insert(n);
    return ans;
}

multiset<int, greater<int>> ms;
map<int, int> cnt;
map<int, bool> on;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    cin >> n;
    while (n--) {
        cin >> d;
        on[d] = !on[d];
        divisors(d);
        for (int div: ans) {
            int c = cnt[div];
            if (on[d]) {
                if (ms.find(c) != ms.end()) {
                    ms.erase(ms.find(c));
                }
                ms.insert(c + 1);
                cnt[div]++;
            } else {
                if (ms.find(c) != ms.end())
                    ms.erase(ms.find(c));
                ms.insert(max(c - 1, 0));
                cnt[div]--;
            }
        }
        ans.clear();
        cout << *ms.begin() << '\n';
    }
    
    return 0;
}