#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int r, n, i = 1;

    while((cin >> r >> n) && r != 0 && n != 0) {
        cout << "Case " << i << ": ";
        if (r - n <= 0) cout << 0;
        else if (r - n <= n) cout << 1;
        else {
            int sufs = (r - 1) / n;
            if (sufs > 26) {
                cout << "garantido";
            } else {
                cout << sufs;
            }
        }
        cout << '\n';
        i++;
    }

    return 0;
}
