#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k, a;
    cin >> n;

    vector<vector<int>> gifts(n + 1, vector<int>(0));

    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            gifts[a].push_back(i + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (int) gifts[i].size();
        for (int j = 0; j < (int) gifts[i].size(); j++) {
            cout << ' ' << gifts[i][j];
        }
        cout << '\n';
    }

    return 0;
}
