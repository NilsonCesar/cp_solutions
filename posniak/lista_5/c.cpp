#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int N, D, T, M, C;
    vector<pair<long long, string>> sabores(5);
    sabores[0] = {0, "NINHO"};
    sabores[1] = {0, "CONDENSADO"};
    sabores[2] = {0, "TAPIOCA"};
    sabores[3] = {0, "MORANGO"};
    sabores[4] = {0, "CHOCOLATE"};

    while (cin >> N >> D >> T >> M >> C) {
        sabores[0].first += N;
        sabores[1].first += D;
        sabores[2].first += T;
        sabores[3].first += M;
        sabores[4].first += C;
    }

    string sabor;
    int maxQtd = 0;

    for (int i = 0; i < 5; i++) {
        if (maxQtd < sabores[i].first) {
            sabor = sabores[i].second;
            maxQtd = sabores[i].first;
        }
    }

    cout << sabor << '\n';

    return 0;
}
