#include <bits/stdc++.h>

using namespace std;

bool valid(string &s) {
    if ((int) s.size() != 11) return false;
    if (s[0] != '1') return false;
    if (s[1] == '0') return false;
    if (s[2] != '9') return false;
    return true;
}

set<string> ans;

void solve(string ts, int i, string &s) {
    if ((int) s.size() - i == 11 - ts.size()) {
        for (; i < (int) s.size(); i++) ts.push_back(s[i]);
        if (valid(ts)) ans.insert(ts);
        return;
    }

    if ((int) ts.size() == 11) {
        if (valid(ts)) ans.insert(ts);
        return;
    }

    ts.push_back('1');
    solve(ts, i, s);
    ts.pop_back();
    
    ts.push_back('9');
    solve(ts, i, s);
    ts.pop_back();

    if (i < (int) s.size()) {
        ts.push_back(s[i]);
        solve(ts, i + 1, s);
        ts.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    
    if ((int) s.size() == 11) {
        if (valid(s))
            cout << 1 << '\n' << s << '\n';
        else
            cout << 0 << '\n';
        return 0;
    }

    if ((int) s.size() > 11) {
        cout << 0 << '\n';
        return 0;
    }

    solve("", 0, s);

    cout << ans.size() << '\n';

    for (string a: ans) {
        cout << a << '\n';
    }

    return 0;
}