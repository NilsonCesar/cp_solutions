#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

struct Node {
    long long count;
    long long sum;

    Node(long long c = 0, long long s = 0) {
        count = c;
        sum = s;
    }
};


const int MAX_VAL = 500005; 
Node tree[4 * MAX_VAL];
long long A[MAX_VAL];

Node merge(Node left_child, Node right_child) {
    long long parent_count = left_child.count + right_child.count;
    long long parent_sum = left_child.sum + right_child.sum;
    
    return Node(parent_count, parent_sum);
}

void update(int node, int start, int end, int pos, int count_change, long long sum_change) {
    if (start == end) {
        tree[node].count = tree[node].count + count_change;
        tree[node].sum = tree[node].sum + sum_change;
        return;
    }

    int mid = (start + end) / 2;
    
    if (pos <= mid) {
        update(2 * node, start, mid, pos, count_change, sum_change);
    } else {
        update(2 * node + 1, mid + 1, end, pos, count_change, sum_change);
    }
    
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int L, int R) {
    if (start > R || end < L) {
        return Node(0, 0); 
    }

    if (start >= L && end <= R) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    Node left_result = query(2 * node, start, mid, L, R);
    Node right_result = query(2 * node + 1, mid + 1, end, L, R);
    
    return merge(left_result, right_result);
}


int main(void) {
    mainIO();
    long long n, q, op, x, y;
    cin >> n >> q;
    for (int i = 0; i < n; i++) 
        cin >> A[i];
    for (int i = 0; i < n; i++) {
        update(1, 0, MAX_VAL, A[i], 1, A[i]);
    }
    while(q--) {
        cin >> op >> x >> y;

        if (op == 1) {
            x--;
            update(1, 0, MAX_VAL, A[x], -1, -A[x]);
            A[x] = y;
            update(1, 0, MAX_VAL, y, +1, +y);
        } else {
            if (x > y) {
                cout << x * n << '\n';
                continue;
            }

            cout << query(1, 0, MAX_VAL, 0, x - 1).count * x + query(1, 0, MAX_VAL, x, y).sum + query(1, 0, MAX_VAL, y + 1, MAX_VAL).count * y << '\n';
        }
    }

    return 0;
}
