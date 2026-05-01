#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int t, i = 1;
    cin >> t;

    for (int j = 0; j < t; j++) {
        if (i != 1) cout << '\n';
        int p, n1, n2;
        cin >> p;
        string a, b;
        cin >> a >> b;
        cout << "Teste " << i << '\n';
        for (int i = 0; i < p; i++) {
            cin >> n1 >> n2;
            cout << ((n1 + n2) % 2 == 0 ? a : b) << '\n';
        }
        i++;
    }

    // while((cin >> t) && t != 0) {
    //     if (i != 1) cout << '\n';
    //     int n1, n2;
    //     string a, b;
    //     cin >> a >> b;
    //     cout << "Teste " << i << '\n';
    //     for (int i = 0; i < t; i++) {
    //         cin >> n1 >> n2;
    //         cout << ((n1 + n2) % 2 == 0 ? a : b) << '\n';
    //     }
    //     i++;
    // }

    return 0;
}
