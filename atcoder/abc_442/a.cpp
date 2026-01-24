#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string s;
    cin >> s;
    int dots = 0;
    for (char c : s) {
        dots += (c == 'i' || c == 'j');
    }

    cout << dots << '\n';

    return 0;
}
