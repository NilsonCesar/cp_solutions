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

    string s, t;
    cin >> s >> t;

    vector<vector<int>> lcs_size(s.size() + 1, vector<int>(t.size() + 1));

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = t.size() - 1; j >= 0; j--) {
            if (s[i] == t[j]) lcs_size[i][j] = 1 + lcs_size[i + 1][j + 1];
            else lcs_size[i][j] = max(lcs_size[i + 1][j], lcs_size[i][j + 1]);
        }
    }

    string lcs = "";
    int i = 0, j = 0;

    while(i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            lcs.push_back(s[i]);
            i++; j++;
        } 
        else if (lcs_size[i + 1][j] >= lcs_size[i][j + 1]) i++;
        else j++;
    }

    cout << lcs << '\n';

    return 0;
}
