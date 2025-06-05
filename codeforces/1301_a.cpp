#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int t;
    cin >> t;

    while(t--) {
        string a, b, c;
        bool no = false;
        cin >> a >> b >> c;
        for (int i = 0; i < (int) a.size(); i++) {
            map<char, int> qtd;
            qtd[a[i]] += 1;
            qtd[b[i]] += 1;
            qtd[c[i]] += 1;
            if (qtd[a[i]] != 3 && ((qtd[a[i]] != 2 && qtd[b[i]] != 2) || a[i] == b[i])) {
                no = true;
                break;
            }
        }

        cout << (no ? "NO" : "YES");
        cout << '\n';
    }

    return 0;
}
