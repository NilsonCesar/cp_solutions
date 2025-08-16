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
    if (s == "red") cout << "SSS";
    else if (s == "blue") cout << "FFF";
    else if (s == "green") cout << "MMM";
    else cout << "Unknown";
    cout << '\n';

    return 0;
}
