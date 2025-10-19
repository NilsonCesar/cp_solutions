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
    int q, op;
    cin >> q;
    char c;
    vector<char> s;
    int count = 0;
    int first_inv_end = -1;

    while(q--) {
        cin >> op;

        if (op == 1) {
            cin >> c;
            s.push_back(c);
            if (count == 0 && c == ')' && first_inv_end == -1) {
                first_inv_end = (int) s.size();
            }
            count += (c == '(' ? 1 : -1);
        } else {
            char b = s.back();
            s.pop_back();
            if ((int) s.size() < first_inv_end)
                first_inv_end = -1;
            count += (b == '(' ? -1 : 1);
        }

        cout << ((!count && first_inv_end == -1) ? "Yes" : "No") << '\n';
    }

    return 0;
}
