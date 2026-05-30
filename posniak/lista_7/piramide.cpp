#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, layer = 0, cnt = 1, qtd = 0;
    cin >> n;
    vector<vector<int>> piramide(n, vector<int>(n, 0));


    while (qtd < n * n && cnt <= n * n) {
        for (int i = layer; i < n - layer; i++) {
            piramide[i][layer] = cnt;
            qtd++;
        }

        for (int i = layer; i < n - layer; i++) {
            piramide[layer][i] = cnt;
            qtd++;
        }

        for (int i = layer; i < n - layer; i++) {
            piramide[i][n - layer - 1] = cnt;
            qtd++;
        }

        for (int i = layer; i < n - layer; i++) {
            piramide[n - layer - 1][i] = cnt;
            qtd++;
        }

        qtd -= 4;
        cnt++;
        layer++;
    }

    if (n > 2) {
        if (n % 2 == 1) {
            piramide[n / 2][n / 2] = n / 2 + 1;
        } else if (n != 2) {
            piramide[n / 2 - 1][n / 2 - 1] = n / 2;
            piramide[n / 2 - 1][n / 2] = n / 2;
            piramide[n / 2][n / 2 - 1] = n / 2;
            piramide[n / 2][n / 2] = n / 2;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << piramide[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
