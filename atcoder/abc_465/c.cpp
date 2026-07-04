#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    string s;
    cin >> n >> s;

    vector<int> sumpref(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'o') {
            sumpref[1] += 1;
            sumpref[i + 1] += -1; 
        }
    }

    for (int i = 1; i <= n; i++) {
        sumpref[i] += sumpref[i - 1];
    }

    vector<int> c, dc;

    for (int i = 1; i <= n; i++) {
        if (sumpref[i] % 2 == 0) c.push_back(i);
        else dc.push_back(i);
    }

    for (int i = (int) dc.size() - 1; i >= 0; i--) {
        cout << dc[i] << ' ';
    }

    for (int i = 0; i < c.size(); i++)
        cout << c[i] << ' ';
    cout << '\n';


    return 0;
}
