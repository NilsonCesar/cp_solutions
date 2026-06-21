#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n, k;
vector<pair<long long, long long>> clothes;

bool check(long long d) {
    int choosed = 1;
    int last_r = clothes[0].second;

    if (k == 1) return true;

    for (int i = 1; i < n; i++) {
        if (clothes[i].first >= last_r + d) {
            last_r = clothes[i].second;
            choosed++;
        }

        if (k == choosed) return true;
    }

    return false;
}

int main(void) {_
    cin >> n >> k;
    clothes.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> clothes[i].second >> clothes[i].first;
    }

    sort(clothes.begin(), clothes.end());
    int c;

    for (int i = 0; i < n; i++) {
        c = clothes[i].first;
        clothes[i].first = clothes[i].second;
        clothes[i].second = c;
    }

    long long l = 1, r = 2e18;
    long long ans = -1;

    while (l <= r) {
        long long mid = (l + r) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
