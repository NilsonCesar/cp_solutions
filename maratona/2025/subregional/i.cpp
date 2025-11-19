#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define INF 2000000100

int main(void) {
    mainIO();

    int n, x, y, last_x, last_y;
    cin >> n >> last_x >> last_y;

    vector<int> dist(n - 1);
    int soma = 0, vmin = 0, vmax = INF;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        dist[i - 1] = abs(last_x - x) + abs(last_y - y);
        soma += dist[i - 1] * (i % 2 ? 1 : -1);

        if (i % 2)
            vmax = min(vmax, soma);
        else
            vmin = max(vmin, soma);
        last_x = x;
        last_y = y;
    }

    cout << (vmin < vmax - 1 ? vmax - 1 : -1) << '\n';

    return 0;
}
