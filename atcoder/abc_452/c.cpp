#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    int n;
    cin >> n;
    vector<pair<int, int>> ribs(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ribs[i].first >> ribs[i].second;
    }

    int m;
    cin >> m;
    vector<string> words(m);
    vector<set<char>> valid_chars(n);

    for (int i = 0; i < m; i++) {
        cin >> words[i];
        for (int j = 0; j < n; j++) {
            if (words[i].length() == ribs[j].first) {
                valid_chars[j].insert(words[i][ribs[j].second - 1]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (words[i].length() != n) {
            cout << "No" << '\n';
            continue;
        }
        bool valid = true;

        for (int j = 0; j < n; j++) {
            if (!valid_chars[j].count(words[i][j])) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "Yes" : "No") << '\n';
    }

    return 0;
}
