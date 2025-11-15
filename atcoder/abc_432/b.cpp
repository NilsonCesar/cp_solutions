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
    string x;
    cin >> x;
    multiset<int> d;
    int z = 0;

    for (char dig: x) {
        int n = dig - '0';
        if (n == 0) z++;
        else d.insert(n);
    }

    int a = *d.begin();
    cout << a;
    d.erase(d.find(a));
    for (int i = 0; i < z; i++)
        cout << 0;
    while(!d.empty()) {
        a = *d.begin();
        cout << a;
        d.erase(d.find(a));
    }
    cout << '\n';

    return 0;
}
