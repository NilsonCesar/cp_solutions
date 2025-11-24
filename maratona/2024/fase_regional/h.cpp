#include <bits/stdc++.h>

using namespace std;

string m, n, resp;

int extrair_bit(int &mask) {
    int ret = mask % 2;
    mask /= 2;
    return ret;
}

bool verify(int mask) {
    int mod = 0;
    for (int i = 0; i < n.size(); i++) {
        mod = mod * 2 + (n[i] == '*' ? extrair_bit(mask) : n[i] - '0');
    }
    int rest = 0, bit;
    for (int i = 0; i < m.size(); i++) {
        bit = (m[i] == '*' ? extrair_bit(mask) : m[i] - '0');
        resp[i] = bit + '0';
        rest = (rest * 2 + bit) % mod;
    }

    return rest == 0;
}

int main(void) {
    cin >> m >> n;
    resp = m;

    int cnt = 0;
    for (int i = 0; i < m.size(); i++) {
        if (m[i] == '*') cnt++;
    }

    for (int i = 0; i < n.size(); i++) {
        if (n[i] == '*') cnt++;
    }

    int lim_mask = 1 << cnt;

    for (int mask = 0; mask < lim_mask; mask++) {
        if (verify(mask)) {
            cout << resp << '\n';
            break; 
        }
    }

    return 0;
}