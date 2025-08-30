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
    long long n, ans1 = 0, ans2 = 0;
    string s;
    cin >> n >> s;
    vector<int> A;

    for (int i = 0; i < 2 * n; i++)
        if (s[i] == 'A')
            A.push_back(i);

    for (int i = 0; i < n; i++) {
        ans1 += abs(A[i] - i * 2);
        ans2 += abs(A[i] - (i * 2 + 1));
    }

    cout << min(ans1, ans2) << '\n';

    return 0;
}
