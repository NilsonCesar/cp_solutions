#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, p;
    cin >> n;
    vector<vector<int>> trilhas(n);
    for (int i = 0; i < n; i++) {
        cin >> p;
        trilhas[i].resize(p);

        for (int j = 0; j < p; j++) {
            cin >> trilhas[i][j];
        }
    }

    int ans = 0, ansL = INF;

    for (int i = 0; i < n; i++) {
        int l = 0;

        for (int j = 0; j < (int) trilhas[i].size() - 1; j++) {
            l += max(trilhas[i][j + 1] - trilhas[i][j], 0);
        }

        if (l < ansL) {
            ansL = l;
            ans = i + 1;
        }

        l = 0;
        for (int j = (int) trilhas[i].size() - 1; j > 0; j--) {
            l += max(trilhas[i][j - 1] - trilhas[i][j], 0);
        }

        if (l < ansL) {
            ansL = l;
            ans = i + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
