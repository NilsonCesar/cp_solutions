#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    long long n, t = 0, r = 0;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for(int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());
    
    for(int i = 0; i < n; i++) {
        t += tasks[i].first;
        r += tasks[i].second - t;
    }
    
    cout << r << '\n';

    return 0;
}
