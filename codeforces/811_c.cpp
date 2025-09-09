#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int n;
vector<int> people;
map<int, int> freq, freqSeq, visited;
long long memo[5010][5010];

long long dp(int l, int r) {
    if (memo[l][r] != -1) return memo[l][r];
    bool valid = true;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            freqSeq.clear();
            for (int k = i; k <= j; k++)
                freqSeq[people[k]]++;
            for (int k = i; k <= j; k++) {
                if (freqSeq[people[k]] != freq[people[k]]) {
                    valid = false;
                    break;
                }
            } 
            if (!valid) break;
            if (memo[i][j] != -1) {
                memo[l][r] = max(memo[l][r], memo[i][j]);
            }
            visited.clear();

            for (int k = i; k <= j; k++) {
                if (freqSeq[people[k]] != freq[people[k]]) {
                    valid = false;
                    break;
                }
            } 
        }
    }
}

int main(void) {
    mainIO();
    cin >> n;
    people.resize(n);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; i++) {
        cin >> people[i];
        freq[people[i]]++;
    }
    cout << dp(0, n - 1) << '\n';

    return 0;
}
