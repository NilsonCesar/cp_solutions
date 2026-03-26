#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 100007

int main(void) {_
    string bits;
    cin >> bits;
    multiset<int> l;
    set<vector<int>> bit_intervals;
    int i = 0;
    while (i < (int) bits.size()) {
        int j = i;
        while (j < (int) bits.size() && bits[j] == bits[i]) {
            j++;
        } 
        bit_intervals.insert({j - 1, i, ((bits[i] != '0'))});
        l.insert(j - i);
        i = j;
    }

    int n, q;
    cin >> n;

    while(n--) {
        cin >> q; q--;
        vector<int> qv = {q, q, 0};
        auto bit_interval = bit_intervals.upper_bound(qv);
        if (bit_interval == bit_intervals.end()) bit_interval--;
        else if ((*bit_interval)[1] > q) bit_interval--;
        else if ((*bit_interval)[0] < q) bit_interval++;
        int right = (*bit_interval)[0], left = (*bit_interval)[1], s = (*bit_interval)[2];

        if (left == q && q == right) {
            int le, re;
            if (bit_interval == bit_intervals.begin()) {
                le = left;
            } else {
                bit_interval--;
                int rr = (*bit_interval)[0], ll = (*bit_interval)[1];
                l.erase(l.find(rr - ll + 1));
                bit_interval = bit_intervals.erase(bit_interval);
                le = ll;
            }
            l.erase(l.find(1));
            bit_interval = bit_intervals.erase(bit_interval);

            if (bit_interval == bit_intervals.end()) {
                re = -1 + (int) bits.size();
            } else {
                int rr = (*bit_interval)[0], ll = (*bit_interval)[1];
                l.erase(l.find(rr - ll + 1));
                bit_interval = bit_intervals.erase(bit_interval);
                re = rr;
            }

            l.insert(re - le + 1);
            bit_intervals.insert({re, le, !s});

        } else if (left == q) {
            l.erase(l.find(right - left + 1));
            l.insert(right - q);
            bit_intervals.erase({right, left, s});
            bit_intervals.insert({right, q + 1, s});
            if (bit_interval == bit_intervals.begin()) {
                l.insert(1);
                bit_intervals.insert({q, q, !s});
            } else {
                bit_interval--;
                int rr = (*bit_interval)[0], ll = (*bit_interval)[1];
                l.erase(l.find(rr - ll + 1));
                l.insert(rr - ll + 2);
                bit_intervals.erase({rr, ll, !s});
                bit_intervals.insert({rr + 1, ll, !s});
            }
        } else if (right == q) {
            l.erase(l.find(right - left + 1));
            l.insert(q - left);
            bit_interval = bit_intervals.erase(bit_interval);
            bit_intervals.insert({q - 1, left, s});
            if (bit_interval == bit_intervals.end()) {
                l.insert(1);
                bit_intervals.insert({q, q, !s});
            } else {
                int rr = (*bit_interval)[0], ll = (*bit_interval)[1];
                l.erase(l.find(rr - ll + 1));
                l.insert(rr - ll + 2);
                bit_intervals.erase({rr, ll, !s});
                bit_intervals.insert({rr, ll - 1, !s});
            }
        } else {
            l.erase(l.find(right - left + 1));
            l.insert(q - left);
            l.insert(1);
            l.insert(right - q);
            bit_intervals.erase({right, left, s});
            bit_intervals.insert({q - 1, left, s});
            bit_intervals.insert({q, q, !s});
            bit_intervals.insert({right, q + 1, s});
        }

        cout << *l.rbegin() << ' ';
    }
    cout << '\n';

    return 0;
}
