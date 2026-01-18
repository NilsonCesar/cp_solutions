#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, i = 0;

    while(i < n) {
        int seq = 0;
        while(i < n && s[i] == 'a') {
            seq++;
            i++;
        }
        i++;
        ans += (seq >= 2 ? seq : 0);
    }

    cout << ans << '\n';

    return 0;
}
