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
    int n;
    cin >> n;
    long long trailing_zeros = 0;

    for (int i = 5; n / i >= 1; i *= 5)
        trailing_zeros += n / i;

    cout << trailing_zeros << '\n'; 
    return 0;
}
