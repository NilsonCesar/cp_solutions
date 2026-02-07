#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string n;
    cin >> n;
    bool valid = 1;
    char d = n[0];
    for (char c : n) {
        if (d != c) {
            valid = 0;
            break;
        }
    }
    cout << (valid ? "Yes" : "No") << '\n';

    return 0;
}
