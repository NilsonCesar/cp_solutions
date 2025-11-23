#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int i = 3;
    vector<int> ans(40 + 1, 0);
    ans[1] = 1;
    ans[2] = 2;

    while(i <= n) {
        ans[i] = ans[i - 1] + ans[i - 2];
        i++;
    }

    cout << ans[n] << '\n';

    return 0;
}