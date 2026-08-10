#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(void) {_
    map<int, long long> cnt;
    int x = 0;

    int n, p;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p;
        cnt[p]++;
        if (cnt[p] > cnt[x]) {
            x = p;
        }
        for (int j = 2; j * j <= p; j++) {
            if (p % j == 0) {
                cnt[j]++;
                if (cnt[j] > cnt[x]) {
                    x = j;
                }
                cnt[p / j]++;
                if (cnt[p / j] > cnt[x]) {
                    x = p / j;
                }
            }
        }
    }

    cout << x << '\n';

    return 0;
}