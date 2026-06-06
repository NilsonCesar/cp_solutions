#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int prefix[500 + 7][500 + 7];

int main(void) {_
    int h, w, k;
    cin >> h >> w >> k;
    string s;

    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 1; j <= w; j++) {
            prefix[i + 1][j] = prefix[i][j] + prefix[i + 1][j - 1]
                - prefix[i][j - 1] + (s[j - 1] - '0');
        }
    }

    long long ans = 0;
    unordered_map<int, int> m;

    for (int r1 = 1; r1 <= h; r1++) {
        for (int r2 = r1; r2 <= h; r2++) {
            m[0] = 1;
            for (int c2 = 1; c2 <= w; c2++) {
                int p = prefix[r2][c2] - prefix[r1 - 1][c2];
                ans += m[p - k];
                m[p]++;
            }
            m.clear();
        }
    }

    cout << ans << '\n';

    return 0;
}
