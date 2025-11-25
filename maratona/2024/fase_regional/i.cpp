#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 1000100
#define MAXN 100100
#define MOD 1000000007

int n;
int cnt[INF];
bool pr[INF];
int fator[INF];
int pot2[MAXN];

vector<int> lista, ret;

void gera_combinacoes(int i, int mult) {
    if (i == (int) lista.size()) {
        ret.push_back(mult);
        return;
    }

    gera_combinacoes(i + 1, mult);
    gera_combinacoes(i + 1, mult * lista[i] * -1);
}

void gera_numeros(int k) {
    set<int> s;
    while (k > 1) {
        s.insert(fator[k]);
        k /= fator[k];
    }
    lista.clear();
    for (auto x: s) lista.push_back(x);
    ret.clear();
    gera_combinacoes(0, 1);
}

int main(void) {_

    for (int i = 0; i < INF; i++) pr[i] = true;
    pr[1] = false;

    for (int i = 2; i < INF; i++) {
        if (pr[i]) {
            fator[i] = i;
            for (long long j = 1LL * i * i; j < INF; j += i) {
                pr[j] = false;
                fator[j] = i;
            }
        }
    }

    cin >> n;

    pot2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot2[i] = (pot2[i - 1] * 2) % MOD;
    }

    int k;
    for (int  i = 0; i < n; i++) {
        cin >> k;
        gera_numeros(k);
        for (auto x: ret) cnt[abs(x)]++;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        gera_numeros(k);
        int soma = 0;
        for (auto x: ret) {
            soma += cnt[abs(x)] * (x/abs(x));
        }
        cout << pot2[soma] << '\n';
    }

    return 0;
}
