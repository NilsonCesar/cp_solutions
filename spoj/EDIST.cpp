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
    int t;
    cin >> t;
    while(t--) {
        string A, B;
        cin >> A >> B;
        vector<vector<int>> lcs((int) A.size() + 7, vector<int>((int) B.size() + 7));

        for (int i = 0; i <= (int) A.size(); i++)
            lcs[i][0] = i;
        for (int j = 0; j <= (int) B.size(); j++)
            lcs[0][j] = j;

        for (int i = (int) A.size(); i > 0; i--) {
            for (int j = (int) B.size(); j > 0; j--) {
                if (A[i - 1] == B[j - 1]) lcs[i][j] = lcs[i + 1][j + 1];
                else {
                    lcs[i][j] = 1 + min(lcs[i + 1][j + 1], min(lcs[i][j + 1], lcs[i + 1][j]));
                }
            }
        }

        // for (int i = 1; i <= (int) A.size(); i++) {
        //     for (int j = 1; j <= (int) B.size(); j++) {
        //         if (A[i - 1] == B[j - 1]) lcs[i][j] = lcs[i - 1][j - 1]; // <-- corner case
        //         else {
        //             lcs[i][j] = 1 + min(lcs[i - 1][j - 1], min(lcs[i][j - 1], lcs[i - 1][j]));
        //         }
        //     }
        // }

        cout << lcs[(int) A.size()][(int) B.size()] << '\n';
    }


    return 0;
}
