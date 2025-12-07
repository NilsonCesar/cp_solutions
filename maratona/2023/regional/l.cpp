#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int i = 0, n = (int) s.size();
    vector<bool> visited(n, false);
    vector<char> ans(n);
    while (i < n) {
        if (visited[i]) {
            i++;
            continue;
        }
        multiset<char> letters;
        for (int j = i; j < n; j += k) {
            letters.insert(s[j]);
            visited[j] = true;
        }
        int j = i;
        for (char c: letters) {
            ans[j] = c;
            j += k;
        }
        i++;
    }

    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
    return 0;
}