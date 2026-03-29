#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios_base::sync_with_stdio(0);

int main() {_
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> people(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        cin >> people[i].first >> people[i].second;
    }

    for (int i = 0; i < n; i++) {
        int time;
        if (visited[i]) continue;
        if (ans >= people[i].first) {
            visited[i] = true;
            time = ans + 10;

            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue;
                if (people[j].second == people[i].second && people[j].first <= ans) visited[j] = true;
            }
        } else {
            time = people[i].first + 10;
        }

        for (int j = i + 1; j < n; j++) {
            if (visited[j]) continue;
            if (people[j].second == people[i].second && people[j].first <= time) {
                visited[j] = true;
                time = people[j].first + 10;
            }
            if (people[j].first > time) break;
        }

        ans = max(ans, time);
    }

    cout << ans << '\n';

    return 0;
}