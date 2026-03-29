#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios_base::sync_with_stdio(0);

int main() {_
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> blocks(n), sorted_blocks(n);
    for (int i = 0; i < n; i++) {
        cin >> blocks[i].first >> blocks[i].second;
        sorted_blocks[i] = blocks[i];
    }
    sort(sorted_blocks.begin(), sorted_blocks.end());

    for (int i = 0; i < n; i++) {
        if (blocks[i].second != sorted_blocks[i].second) {
            cout << 'N' << '\n';
            return 0;
        }
    }

    cout << 'Y' << '\n';

    return 0;
}