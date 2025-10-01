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
    cin >> s;
    int n = (int) s.size();
    int odd = 0;
    char oddC = '0';
    map<char, int> count;

    for(char c: s)
        count[c]++;
    for(char c: s) {
        if (oddC != c) odd += (count[c] % 2);
        if (count[c] % 2 && oddC != c) 
            oddC = c;
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    vector<char> ans(n, '0');

    int l = 0, r = n - 1;
    for(char c: s) {
        if (c == oddC) continue;
        int i = l, j = r;
        while(count[c]) {
            ans[i++] = c;
            ans[j--] = c;
            count[c] -= 2;
        }
        l = i; r = j;
    }

    for (int i = l; i <= r; i++)
        ans[i] = oddC;

    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << '\n';

    return 0;
}
