#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string s;
    cin >> s;

    int w = 0, e = 0;

    for (char c: s) {
        w += c == 'W';
        e += c == 'E';
    }

    cout << (e > w ? "East" : "West") << '\n';

    return 0;
}
