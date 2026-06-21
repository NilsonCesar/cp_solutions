#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    char x;
    cin >> n >> x;
    int v = x - 'A';
    bool ans = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if (j == v && x == 'o') ans = true;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
