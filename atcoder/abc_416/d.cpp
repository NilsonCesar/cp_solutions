#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

bool check(int k, int N, long long M, const vector<int>& A, const vector<int>& B) {
    if (k == 0) {
        return true;
    }
    for (int i = 0; i < k; ++i) {
        if ((long long)A[N - k + i] + B[N - 1 - i] < M) {
            return false;
        }
    }
    return true;
}

int main() {
    mainIO();
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long M;
        cin >> N >> M;
        vector<int> A(N), B(N);
        long long sum_A = 0, sum_B = 0;

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            sum_A += A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
            sum_B += B[i];
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int low = 0, high = N;
        int k_max = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, N, M, A, B)) {
                k_max = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        long long result = sum_A + sum_B - (long long)k_max * M;
        cout << result << '\n';
    }
    return 0;
}