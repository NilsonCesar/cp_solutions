#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {
    int n, m, idx = 0;
    cin >> n >> m;
    int a, d, b;
    set<int> ans;
    map<int, int> freq;
    vector<vector<int>> events;

    for (int i = 0; i < n; i++) {
        cin >> a >> d >> b;

        if (d == 1 || a == b) {
            freq[b]++;
            ans.insert(b);
            continue;
        }

        ans.insert(a);
        freq[a]++;
        events.push_back({d, a, b});
    }

    sort(events.begin(), events.end());

    for (int i = 1; i <= m; i++) {
        while(idx < (int) events.size() && events[idx][0] == i) {
            freq[events[idx][1]]--;
            freq[events[idx][2]]++;

            if (freq[events[idx][1]] == 0) {
                ans.erase(events[idx][1]);
            }

            ans.insert(events[idx][2]);
            idx++;
        }

        cout << ans.size() << '\n';
    }


    return 0;
}
