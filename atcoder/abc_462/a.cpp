#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string s;
    cin >> s;

    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] - '0' <= 9 and s[i] - '0' >= 0) {
            cout << s[i] - '0';
        }
    }
    cout << '\n';

    return 0;
}
