#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int n;
int ans = 0;
vector<int> P, Q;

bool less_than_q(vector<int> S) {
    for (int i = 0; i < n; i++) {
        if (S[i] < Q[i]) return true;
        if (S[i] > Q[i]) return false;
    }
    return false;
}

bool greater_than_p(vector<int> S) {
    for (int i = 0; i < n; i++) {
        if (S[i] > P[i]) return true;
        if (S[i] < P[i]) return false;
    }
    return false;
}

void solve(vector<int> S, vector<bool> used, int i) {
    if (i == n) {
        ans += less_than_q(S) && greater_than_p(S);
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            used[j] = true;
            S.push_back(j);
            solve(S, used, i + 1);
            S.pop_back();
            used[j] = false;
        }
    }
}

int main(void) {_
    cin >> n;
    P.resize(n);
    Q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> Q[i];
    }
    solve(vector<int>(), vector<bool>(n + 1, false), 0);
    cout << ans << '\n';
    return 0;
}
