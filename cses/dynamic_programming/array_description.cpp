#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

long long ans;
int n, m;
int x[MAXN], memo[MAXN][107];

// int solve(int i) {
//     if(i == n + 1) {
//         ans++;
//         memo[i]++;
//         return memo[i];
//     }
//     if (x[i] != 0) {
//         memo[i] = solve(i + 1);
//         return memo[i];
//     }

//     for (int j = 1; j <= m; j++) {
//         // cout << j << '\n';
//         // cout << abs(x[i - 1] - j) << " " << abs(x[i + 1] - j) << '\n';
//         if (abs(x[i - 1] - j) <= 1 && abs(x[i + 1] - j) <= 1) {
//             x[i] = j;
//             memo[i] += solve(i + 1);
//         }
//     }
    
//     return memo[i];
// }


bool validate() {
    bool valid = true;
    for (int i = 1; i <= n; i++) {
        cout << x[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            valid = false;
            break;
        }
        if(!(abs(x[i - 1] - x[i]) <= 1 && abs(x[i + 1] - x[i]) <= 1)) {
            valid = false;
            break;
        }
    }
    ans += valid;
    return valid;
}

long long solve(int i, int j) {
    if (i == n + 1) {
        if (validate()) return 1;
        else return 0;
    }

    if (memo[i][j]) return memo[i][j];

    if (x[i] != 0) {
        memo[i][j] += solve(i + 1, j);
        return memo[i][j];
    }

    for (int j = 1; j <= m; j++) {
        x[i] = j;
        memo[i][j] += solve(i + 1, j);
        x[i] = 0;
    }

    return memo[i][j];
} 

int main(void) {_
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    x[0] = x[1];
    x[n + 1] = x[n];

    if (n == 1 && x[1] == 0) {
        cout << m << '\n';
        return 0;
    } else if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    if (x[1] == 0) {
        for (int i = 1; i <= m; i++) {
            if (x[n] == 0) {
                for (int j = 1; j <= m; j++) {
                    x[1] = x[0] = i;
                    x[n] = x[n + 1] = j;
                    ans += solve(1, x[1]);
                }
                x[n] = 0;
            } else {
                x[1] = x[0] = i;
                ans += solve(1, x[1]);
            }
        }
    } else if (x[n] == 0) {
        for (int i = 1; i <= m; i++) {
            x[n] = x[n + 1] = i;
            ans += solve(1, x[1]);
        }
    } else {
        ans = solve(1, x[1]);
    }
    cout << ans << '\n';
    
    return 0;
}
