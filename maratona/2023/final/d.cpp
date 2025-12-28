#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, g;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
    }
    string secret = dict[0];
    set<char> in;
    for (char c : secret)
        in.insert(c);
    cin >> g;
    while(g--) {
        string tip;
        int count = 0;
        cin >> tip;
        for (int i = 0; i < n; i++) {
            string actTip = "";
            for (int j = 0; j < 5; j++) {
                if (secret[j] == dict[i][j]) {
                    actTip += '*';
                } else if (in.count(dict[i][j])) {
                    actTip += '!';
                } else {
                    actTip += 'X';
                }
            }
            
            if (actTip == tip) count++;
        }

        cout << count << '\n';
    }
}