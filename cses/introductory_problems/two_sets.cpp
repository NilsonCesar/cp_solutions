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
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<int> a, b;
    long long sum_a = 0, sum_b = 0;

    for (int i = n; i >= 1; i--) {
        if (sum_a > sum_b) {
            b.push_back(i);
            sum_b += i;
        } else {
            a.push_back(i);
            sum_a += i;
        }
    }

    if (sum_a == sum_b) {
        cout << "YES" << '\n';
        cout << (int) a.size() << '\n';
        for (int i = -1 + (int) a.size(); i >= 0; i--) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        cout << (int) b.size() << '\n';
        for (int i = -1 + (int) b.size(); i >= 0; i--) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
