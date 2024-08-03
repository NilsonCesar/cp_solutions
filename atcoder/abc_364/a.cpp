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
    int n, eat = 1, count = 0;
    string s;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == "salty") count = 0;
        else count++;

        if(count == 2 && i != n - 1) eat = 0;
    }

    if(eat) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}
