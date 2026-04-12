#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_

    vector<string> norte = {"roraima", "tocantins", "para", "amazonas", "acre", "amapa", "rondonia"};
    string estado;
    cin >> estado;

    for (string e: norte) {
        if (e == estado) {
            cout << "Regiao Norte" << '\n';
            return 0;
        }
    }

    cout << "Outra regiao" << '\n';

    return 0;
}
