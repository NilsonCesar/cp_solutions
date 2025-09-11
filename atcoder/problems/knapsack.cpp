#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int N, W;
long long memo[110][100000 + 7];
int v[110], w[110];

long long dp(int i, int w_tmp) {
    if (i == N) return 0;
    if (memo[i][w_tmp] != -1) return memo[i][w_tmp];
    memo[i][w_tmp] = dp(i + 1, w_tmp);
    if (w_tmp - w[i] >= 0) memo[i][w_tmp] = max(memo[i][w_tmp], dp(i + 1, w_tmp - w[i]) + v[i]);
    return memo[i][w_tmp];
}

bool peguei[110];

void recupera(int i, int cap) {
    if (i >= N) return;
    if (cap >= w[i] and dp(i + 1, cap) < dp(i + 1, cap - w[i]) + v[i]) {
        peguei[i] = true;
        return recupera(i + 1, cap - w[i]);
    }
    return recupera(i + 1, cap);
}

int main(void) {
    mainIO();
    memset(memo, -1, sizeof(memo));
    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    cout << dp(0, W) << '\n';

    recupera(0, W);
    long long soma_recuperada = 0;

    for (int i = 0; i < N; i++)
        if (peguei[i])
            soma_recuperada += v[i];
    cout << soma_recuperada << '\n';

    return 0;
}
