#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    long long n, x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    if (n < 4) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    sort(a.begin(), a.end());

    unordered_map<long long, pair<int, int>> last_pairs;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long target = x - (a[i].first + a[j].first);
            if (last_pairs.find(target) != last_pairs.end()) {
                cout << last_pairs[target].first << ' ' << last_pairs[target].second << ' ' << a[i].second << ' ' << a[j].second << '\n';
                return 0;
            }
        }

        for (int k = 0; k < i; k++) {
            last_pairs[a[i].first + a[k].first] = {a[k].second, a[i].second};
        }
    }


    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
