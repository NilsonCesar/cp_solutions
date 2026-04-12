#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    vector<vector<double>> tamba(3, vector<double>(4));
    int banca;
    double melhor_preco = INF;
    for (int i = 0; i < 3; i++) {
        cin >> tamba[i][0] >> tamba[i][1] >> tamba[i][2] >> tamba[i][3];
        double soma = tamba[i][0] + tamba[i][1];
        if (min(soma * (1 - tamba[i][2] / 100.00), soma * (1 + tamba[i][3] / 100.00)) < melhor_preco) {
            melhor_preco = min(soma * (1 - tamba[i][2] / 100.00), soma * (1 + tamba[i][3] / 100.00));
            banca = i + 1;
        }
    }

    cout << fixed << setprecision(2);
    cout << "R$ " << melhor_preco << " Banca " << banca << '\n';

    return 0;
}
