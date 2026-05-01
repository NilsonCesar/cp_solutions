#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string a, b;
    cin >> a >> b;
    int x = 0, y = 0;

    for (int i = -1 + (int) a.size(); i >= 0; i--) {
        for (int j = -1 + (int) b.size(); j >= 0; j--) {
            if (a[i] == b[j]) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << '\n';

    return 0;
}
