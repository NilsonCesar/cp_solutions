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
    long long n, m, c;
    long long a;
    cin >> n >> m >> c;
    map<long long, long long> f;
    vector<vector<long long>> sumpref;

    for (int i = 0; i < n; i++) {
        cin >> a;
        f[a]++;
    }

    sumpref.push_back({f.begin()->first, f.begin()->second});
    f.erase(f.begin());
    for(std::map<long long, long long>::iterator iter = f.begin(); iter != f.end(); ++iter) {
        sumpref.push_back({iter->first, iter->second});
        sumpref[(int) sumpref.size() - 1][1] += sumpref[(int) sumpref.size() - 2][1];
    }

    long long ans = 0;

    for (int i = 0; i < (int) sumpref.size(); i++) {
        long long k = sumpref[i][1] + c - 1;
        auto it = std::upper_bound(sumpref.begin() + i, sumpref.end(), k, 
            [](long long value, const vector<long long>& p) {
                return value < p[1];
            }
        );
        long long index = distance(sumpref.begin(), it);
        if (index == (int) sumpref.size()) {
            if (sumpref[index - 1][1] - sumpref[i][1] >= c)
             ans += sumpref[index - 1][1] - sumpref[i][1];
            else {
                long long r = sumpref[index - 1][1] - sumpref[i][1];
                long long k = c - r - 1;
                auto it = std::upper_bound(sumpref.begin(), sumpref.end(), k, 
                    [](long long value, const vector<long long>& p) {
                        return value < p[1];
                    }
                );
                long long index = distance(sumpref.begin(), it);
                ans += sumpref[index][1] + r;
            }
        }
        else ans += sumpref[index][1] - sumpref[i][1];
    }
    
    cout << ans << '\n';

    return 0;
}
