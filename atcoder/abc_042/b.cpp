#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, l;
    cin >> n >> l;
    string s;
    multiset<string> x;
    for (int i = 0; i < n; i++) {
        cin >> s;
        x.insert(s);
    }

    for (string c : x)
        cout << c;
    cout << '\n';

    return 0;
}
