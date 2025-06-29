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
    // mainIO();
    string resp;
    int l = 1, r = 1e6, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        cout << mid << '\n' << flush;
        cin >> resp;
        if ((int) resp.length() == 1) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }

    cout << "! " << ans << '\n';

    return 0;
}
