#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, l = 1;
    string s;
    cin >> n >> s;
    for (char c: s) {
        if (l && c != 'o') {
            l = 0;
            cout << c;
        } else if (!l) cout << c;
    }

    return 0;
}
