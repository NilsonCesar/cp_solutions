#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
#define INF 0x3f3f3f3f
#define MAXN 200007

int main(void) {_
    int n, f, max_f = -1;
    cin >> n;
    vector<int> freq(MAXN, 0);
    for (int i = 0; i < n; i++) {
        cin >> f;
        freq[f]++;
        max_f = max(max_f, f);
    }

    vector<int> suffix(max_f + 2, 0);

    for (int i = max_f; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + freq[i];
    }

    vector<int> result;
    int carry = 0;

    for (int i = 0; carry != 0 || i < max_f ; i++) {

        int count = (i + 1 <= max_f ? suffix[i + 1] : 0);
        int sum = count + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    for (int i = 0; i < (int) result.size(); i++)
        cout << result[i];
    cout << '\n';

    return 0;
}
