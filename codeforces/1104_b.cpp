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
    string s;
    vector<char> stack((int) s.size());
    cin >> s;
    int a = 0;

    for (char c : s) {
        if ((int) stack.size() && stack.back() == c) {
            stack.pop_back();
            a = !a;
        } else {
            stack.push_back(c);
        }
    }

    if (a) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}
