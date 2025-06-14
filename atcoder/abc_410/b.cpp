#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int main(void) {
    mainIO();
    int n, q, x;
    cin >> n >> q;
    vector<int> boxes(n + 1, 0), ans(q + 1);
    
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (x >= 1) {
            boxes[x]++;
            ans[i + 1] = x;
        } else {
            int smallest = 100, smallest_idx = 0;
            for (int i = 1; i <= n; i++) {
                if (boxes[i] < smallest) {
                    smallest = boxes[i];
                    smallest_idx = i;
                }
            }
            boxes[smallest_idx]++;
            ans[i + 1] = smallest_idx;
        }
    } 

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
