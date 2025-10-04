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
    string x, y;
    cin >> x >> y;
    map<string, int> os;
    os["Ocelot"] = 0;
    os["Serval"] = 1;
    os["Lynx"] = 2;
    if (os[x] >= os[y]) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}
