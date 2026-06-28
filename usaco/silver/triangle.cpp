#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define max_n 100000
#define mod 1000000007
#define max_c 10000

struct Fence {
    int x;
    int y;
    long long heightsum;
    long long basesum;
};

Fence fences[max_n];
vector<pair<int, int>> xcoords[2 * max_c + 1];
vector<pair<int, int>> ycoords[2 * max_c + 1];

int main(void) {
    mainIO("triangles");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fences[i].x >> fences[i].y;
        xcoords[fences[i].x + max_c].push_back({fences[i].y, i});
        ycoords[fences[i].y + max_c].push_back({fences[i].x, i});
    }

    for (int i = 0; i <= 2 * max_c; i++) {
        if (xcoords[i].size() > 0) {
            long long curr = 0;
            sort(xcoords[i].begin(), xcoords[i].end());
            for (int j = 1; j < (int) xcoords[i].size(); j++) {
                curr += xcoords[i][j].first - xcoords[i][0].first;
            }
            fences[xcoords[i][0].second].heightsum = curr;
            for (int j = 1; j < (int) xcoords[i].size(); j++) {
                curr += (2 * j - xcoords[i].size()) *
                            (xcoords[i][j].first - xcoords[i][j - 1].first);
                fences[xcoords[i][j].second].heightsum = curr;
            }
        }
    }
    
    for (int i = 0; i <= 2 * max_c; i++) {
        if (ycoords[i].size() > 0) {
            long long curr = 0;
            sort(ycoords[i].begin(), ycoords[i].end());
            for (int j = 1; j < (int) ycoords[i].size(); j++) {
                curr += ycoords[i][j].first - ycoords[i][0].first;
            }
            fences[ycoords[i][0].second].basesum = curr;
            for (int j = 1; j < ycoords[i].size(); j++) {
                curr += (2 * j - ycoords[i].size()) *
                            (ycoords[i][j].first - ycoords[i][j - 1].first);
                fences[ycoords[i][j].second].basesum = curr;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += fences[i].basesum * fences[i].heightsum % mod;
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}
