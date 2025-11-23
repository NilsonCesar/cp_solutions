#include <bits/stdc++.h>

using namespace std;

string m, n;
vector<int> all_n;
int M, N, ans = -1;

void make_all_n(int i, int cur_n) {
    if (i == N) {
        all_n.push_back(cur_n);
        return;
    }

    if (n[i] != '*') make_all_n(i + 1, (cur_n << 1) | (n[i] - '0'));
    else {
        make_all_n(i + 1, (cur_n << 1) | 1);
        make_all_n(i + 1, (cur_n << 1));
    }
}

void solve(int i, int mi) {
    // cout << i << ' ' << mi << '\n';
    if(ans != -1) return;
    if (i == M) {
        // cout << "Mi: " << mi << '\n';
        for (int ni : all_n) {
            if (mi % ni == 0) {
                ans = mi;
                return;
            }
        }
        return;
    }

    if (m[i] != '*') solve(i + 1, (mi << 1) | (m[i] - '0'));
    else {
        solve(i + 1, (mi << 1) | 1);
        solve(i + 1, (mi << 1));
    }
}

int main(void) {
    cin >> m >> n;
    M = (int) m.size();
    N = (int) n.size();
    make_all_n(0, 0);
    solve(0, 0);
    vector<short> ans_vec; 
    while(ans) {
        if (ans & 1) ans_vec.push_back(1);
        else ans_vec.push_back(0);
        ans = ans >> 1;
    }

    for (int i = (int) ans_vec.size() - 1; i >= 0; i--)
        cout << ans_vec[i];
    cout << '\n';
    return 0;
}