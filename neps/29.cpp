#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

struct Node {
    int freq[9];

    Node() {
        memset(freq, 0, sizeof(freq));
    }

    void rotate(int k) {
        int tmp[9];
        for (int i = 0; i < 9; i++)
            tmp[(i + k) % 9] = freq[i];
        for (int i = 0; i < 9; i++)
            freq[i] = tmp[i];
    }
};

Node tree[4 * MAXN];
int lazy[4 * MAXN], v[MAXN];

Node combine(Node l, Node r) {
    Node res;
    for (int i = 0; i < 9; i++) {
        res.freq[i] = l.freq[i] + r.freq[i];
    }
    return res;
}

void push(int node, int start, int end) {
    if (lazy[node] == 0) return;
    if (start == end) return;
    int left = 2 * node;
    int right = 2 * node + 1;

    lazy[left] = (lazy[left] + lazy[node]) % 9;
    tree[left].rotate(lazy[node]);

    lazy[right] = (lazy[right] + lazy[node]) % 9;
    tree[right].rotate(lazy[node]);
    lazy[node] = 0;
}

void update(int node, int l, int r, int tl, int tr, int val) {
    push(node, tl , tr);

    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
        tree[node].rotate(val);
        lazy[node] = (lazy[node] + val) % 9;
        return;
    }

    int tm = (tl + tr) / 2;
    update(node*2, l, r, tl, tm, val);
    update(node*2+1, l, r, tm+1, tr, val);
    tree[node] = combine(tree[node*2], tree[node*2+1]);
}

Node query(int node, int l, int r, int tl, int tr) {
    push(node, tl, tr);
    if (r < tl || tr < l) return Node();
    if (l <= tl && tr <= r) return tree[node];
    int tm = (tl + tr) / 2; 
    Node left = query(node*2, l, r, tl, tm);
    Node right = query(node*2+1, l, r, tm + 1, tr);
    return combine(left, right);
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = Node();
        tree[node].freq[1] = 1;
        return;
    }
    int m = (start + end) / 2;
    build(node*2, start, m);
    build(node*2+1, m+1, end);
    tree[node] = combine(tree[node*2], tree[node*2+1]);
}

void print(int node, int tl, int tr) {
    push(node, tl, tr);
    if (tl == tr) {
        for (int i = 0; i < 9; i++) {
            if (tree[node].freq[i] != 0) {
                cout << i << '\n';
                return;
            }
        }
    }
    int tm = (tl + tr) / 2;
    print(node*2, tl, tm);
    print(node*2 + 1, tm + 1, tr);
}

int main(void) {
    int n, q, l, r;
    cin >> n >> q;
    build(1, 0, n - 1);
    while(q--) {
        cin >> l >> r;
        Node ans = query(1, l, r, 0, n - 1);
        int maxFreq = -INF, note;
        for (int i = 0; i < 9; i++)
            if (ans.freq[i] >= maxFreq) {
                note = i;
                maxFreq = ans.freq[i];
            }
        update(1, l, r, 0, n - 1, note);
    }

    print(1, 0, n - 1);
}  