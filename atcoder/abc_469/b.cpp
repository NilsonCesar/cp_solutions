#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    s = '-' + s + '-';
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '-' && s[i] == 'x' && s[i + 1] != 'o') {
            ans++;
        }
        else if (s[i + 1] == '-' && s[i] == 'x' && s[i - 1] != 'o') {
            ans++;
        }
        else if (s[i + 1] == 'x' && s[i - 1] == 'x' && s[i] == 'x') ans++;
    }
    cout << ans << '\n';
    return 0;
}
