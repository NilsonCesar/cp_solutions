#include <bits/stdc++.h>

using namespace std;

int pos[101], n, v[101];
int has = false;
bool memo[5200][5200];

bool solve(int k, int a, int b) {
    if (has) return true;
    if (!memo[a][b]) {
        // cout << "hits here!" << '\n'; 
        return false;
    }
    if (k == n + 1) {
        if (a == b) has = true;
        else memo[a][b] = false;
        return memo[a];
    }

    bool valid = false;
    for (int i = 1; i <= n; i++) {
        if(!pos[i]) {
            pos[i] = k;
            if (a < b || a == b) {
                if (solve(k + 1, a + v[i], b)) {
                    valid = true;
                }
            } else {
                if (solve(k + 1, a, b + v[i])) {
                    valid = true;
                }
            }
            if (has) return true;
            pos[i] = 0;
        }
    }
    memo[a][b] = valid;

    return memo[a];
}

int main(void) {
    for (int i = 0; i < 5200; i++)
        for (int j = 0; j < 5200; j++)
            memo[i][j] = true;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    solve(1, 0, 0);

    if(!has) {
        cout << -1 << '\n';
        return 0;
    }

    int cur = 1;
    while (cur <= n) {
        for (int i = 1; i <= n; i++) {
            if (pos[i] == cur) {
                cout << v[i] << ' ';
                break;
            }
        }
        cur++;
    }
    cout << '\n';

    return 0;
}