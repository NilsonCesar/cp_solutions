#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

bool compare_mountain(vector<int> m1, vector<int> m2) {
    if (m1[0] == m2[0]) return m1[1] > m2[1];
    return m1[0] < m2[0];
}


int main(void) {
    mainIO("mountains");
    int n, x, y;
    cin >> n;
    vector<vector<int>> mountains(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mountains[i][0] = x - y;
        mountains[i][1] = x + y;
    }
    sort(mountains.begin(), mountains.end(), compare_mountain);
    
    int i = 1;
    int ans = 1;
    int max_right = mountains[0][1];

    // for (vector<int> mountain : mountains) {
    //     cout << mountain[0] << ' ' << mountain[1] << '\n';
    // }
    
    while(i < n) {
        while(i < n && max_right >= mountains[i][1]) i++;
        if (i < n) {
            ans++;
            max_right = mountains[i][1];
        }
        i++;
    }

    cout << ans << '\n';
    
    return 0;
}
