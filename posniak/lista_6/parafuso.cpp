#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    map<int, int> parafusos;
    set<int> tamanhos;
    int p;

    while(cin >> p) {
        tamanhos.insert(p);
        parafusos[p]++;
    }

    for (int tamanho: tamanhos) {
        if (parafusos[tamanho] == 1) {
            cout << 'N' << tamanho << " tem apenas um exemplar";
        } else {
            cout << 'N' << tamanho << " tem " << parafusos[tamanho] << " exemplares";
        }
        cout << '\n';
    }

    return 0;
}
