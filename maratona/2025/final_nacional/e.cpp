#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false);

#define MAXQ 300100
#define INF 0x3f3f3f3f

vector<pair<int, int>> vq;
map<int, int> id;
int t[4 * MAXQ], lazy[4 * MAXQ], a[MAXQ];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2 + 1]);
    }
}

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int r, int addend) {
    if (tl > r) return;
    if (tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, min(r, tm), addend);
        update(v*2+1, tm+1, tr, r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int main(void) {_
    int q;
    cin >> q;
    char ch; int x;
    id[0] = 0; 
    for (int i = 0; i < q; i++) {
        cin >> ch >> x;
        vq.push_back({x, ch == '+' ? 1 : -1});
        id[x] = 0;
    }

    int cnt = 0;
    for (auto &p: id ){
        a[cnt] = p.first;
        p.second = cnt++;
    }
    build(1, 0, cnt - 1);

    for (auto [x, i] : vq) {
        update(1, 0, cnt - 1, id[x] - 1, i);
        cout << t[1] << ' ';
    }
    cout << '\n';

    return 0;
}
