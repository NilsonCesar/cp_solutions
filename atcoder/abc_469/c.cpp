#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> idx;
    vector<int> qtd_o(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            idx[++cnt] = i;
        }

        if (s[i] == 'o') {
            qtd_o[i] = qtd_o[max(i - 1, 0)] + 1;
        } else {
            qtd_o[i] = qtd_o[max(i - 1, 0)];
        }
    }

    for (int k = 0; k < n; k++) {
        if (k + 1 > cnt) cout << n << '\n';
        else cout << idx[k + 1] + 1 << '\n';
    }


    return 0;
}
