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
    int n, k;
    // set<string> ans;
    long long ans = 0;
    char c;
    cin >> n >> k;
    vector<string> cards(n), tmp;
    set<string> uni_cards, a, b, d;
    char card[40];

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        uni_cards.insert(cards[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int f = 0; f < k; f++) {
                if (cards[i][f] == cards[j][f]) {
                    card[f] = cards[i][f];
                } else {
                    char c = 'E';
                    if (cards[i][f] != c and cards[j][f] != c) card[f] = c;
                    c = 'T';
                    if (cards[i][f] != c and cards[j][f] != c) card[f] = c;
                    c = 'S';
                    if (cards[i][f] != c and cards[j][f] != c) card[f] = c;
                }
            }
            card[k] = 0;

            if (uni_cards.count(card)) {
                ans++;
                // ans.insert(tmp[0] + tmp[1] + tmp[2]);
            }
        }
    }

    // cout << (long long) ans.size() << '\n';
    cout << ans / 3 << '\n';

    return 0;
}