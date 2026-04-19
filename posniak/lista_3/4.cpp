#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    vector<pair<string, string>> protasio = {{"saude", "branco"}, {"sesc", "branco"}, {"redencao", "cinza"}, {"redencao", "tricolor"}};
    vector<pair<string, string>> ipiranga = {{"saude", "branco"}, {"marinha", "tricolor"}, {"puc", "preto"}};
    vector<pair<string, string>> bento = {{"agronomia", "tricolor"}, {"vale", "amarelo"}, {"vale", "preto"}, {"puc", "preto"}};

    string lugar, cor;
    cin >> lugar >> cor;
    
    vector<pair<string, string>> choosed;

    if (lugar == "protasio") {
        choosed = protasio;
    } else if (lugar == "bento") {
        choosed = bento;
    } else {
        choosed = ipiranga;
    }

    set<string> lugares;

    for(pair<string, string> l : choosed) {
        if (l.second == cor) lugares.insert(l.first);
    }

    if (lugares.size() == 0) cout << "gatou" << '\n';
    else {
        for (string l: lugares) {
            cout << l << ' ';
        }
        cout << '\n';
    }

    return 0;
}
