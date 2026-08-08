#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n, k;
    cin >> n;

    if (n == 1 || n >= 3) {
        cout << 'S' << '\n';
    }

    vector<vector<int>> stacks(n);
    for (int i = 0; i < n; i++) {
        cin >> k;
        stacks[i] = vector<int>(k);
        for (int j = 0; j < k; j++)
            cin >> stacks[i][j];
    }

    if (n == 2) {
        bool valid = true;
        for (int j = (int) stacks[1].size() - 1; j >= 0; j--)
            stacks[0].push_back(stacks[1][j]);
        for (int j = 0; j < (int) stacks[0].size() - 1; j++)
            if (stacks[0][j + 1] < stacks[0][j])
                valid = false;
        cout << (valid ? 'S' : 'N') << '\n';
    }

    return 0;
}
