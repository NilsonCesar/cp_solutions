#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 510

int n, v[MAXN];
int p[MAXN][MAXN];

int func(int i, int j) {
    if (j < i) return 0;
    if (p[i][j] != -1) return p[i][j];
    if (i == j) return p[i][j] = 0;
    
    int ret = 0, len = j - i + 1;
    vector<int> pos(len), seq;
    for (int k = 0; k < n; k++) {
        if (i <= v[k] && v[k] <= j) {
            pos[v[k] - i] = seq.size();
            seq.push_back(v[k] == i ? 0 : 1);
        }
    }
    int troca = 0;
    for (int k = i; k <= j; k++) {
        ret = max(ret, troca + func(i, k - 1) + func(k + 1, j));

        if (k == j) break;

        int l = pos[k - i];
        if (0 <= l - 1 && l + 1 < len && seq[l - 1] * seq[l + 1] == -1) {
            troca--;
        }
        seq[l] = -1;
        if (0 <= l - 1 && seq[l - 1] * seq[l] == -1) troca++;
        if (l + 1 < len && seq[l] * seq[l + 1] == -1) troca++;
        l = pos[k + 1 - i]; 
        if (0 <= l - 1 && seq[l - 1] * seq[l] == -1) troca--;
        if (l + 1 < len && seq[l] * seq[l + 1] == -1) troca--; 
        seq[l] = 0;
        if (0 <= l - 1 && l + 1 < len && seq[l - 1] * seq[l + 1] == -1) {
            troca++;
        }
    }
    return p[i][j] = ret;
}

int main(void) {_
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = i; j < n; j++)
            p[i][j] = -1;
    }
    cout << func(0, n - 1) << '\n';

    return 0;
}
