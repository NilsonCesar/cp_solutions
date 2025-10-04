#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

void hanoi(int n, int start, int end) {
    if (n == 1) {
        cout << start << ' ' << end << '\n';
        return;
    }
    int other = 6 - start - end;
    hanoi(n - 1, start, other);
    cout << start << ' ' << end << '\n';
    hanoi(n - 1, other, end); 
}

int main(void) {
    mainIO();
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3);
    return 0;
}
