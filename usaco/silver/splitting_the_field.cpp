#include <bits/stdc++.h>

using namespace std;
void mainIO(string s = "") {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    if(s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define INF (1e9+7)

int main(void) {
    mainIO("split");
    int n;
    cin >> n;
    long long originalArea;
    vector<vector<long long>> cows(n, vector<long long>(2));
    vector<long long> sufMinX(n + 1, INF), sufMaxX(n + 1, -INF), sufMinY(n + 1, INF), sufMaxY(n + 1, -INF);

    for (int i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1];

    sort(cows.begin(), cows.end());

    for (int i = n - 1; i >= 0; i--) {
        sufMinX[i] = min(sufMinX[i + 1], cows[i][0]);
        sufMaxX[i] = max(sufMaxX[i + 1], cows[i][0]);
        sufMinY[i] = min(sufMinY[i + 1], cows[i][1]);
        sufMaxY[i] = max(sufMaxY[i + 1], cows[i][1]);
    }

    originalArea = (sufMaxX[0] - sufMinX[0]) * (sufMaxY[0] - sufMinY[0]);
    long long xMin = cows[0][0], xMax = cows[0][0], yMin = cows[0][1], yMax = cows[0][1]; 
    long long ans = originalArea;

    for (int i = 0; i < n - 1; i++) {
        xMin = min(xMin, cows[i][0]);
        xMax = max(xMax, cows[i][0]);
        yMin = min(yMin, cows[i][1]);
        yMax = max(yMax, cows[i][1]);
        if (xMax == sufMinX[i + 1] && yMax >= sufMinY[i + 1]) continue;
        ans = min(ans, (xMax - xMin) * (yMax - yMin) + (sufMaxX[i + 1] - sufMinX[i + 1]) * (sufMaxY[i + 1] - sufMinY[i + 1]));
    }

    for (int i = 0; i < n; i++) {
        swap(cows[i][0], cows[i][1]);
    }

    sort(cows.begin(), cows.end());

    sufMinX.clear();
    sufMinX.resize(n + 1, INF);
    sufMaxX.clear();
    sufMaxX.resize(n + 1, -INF);
    sufMinY.clear();
    sufMinY.resize(n + 1, INF);
    sufMaxY.clear();
    sufMaxY.resize(n + 1, -INF);

    for (int i = n - 1; i >= 0; i--) {
        sufMinX[i] = min(sufMinX[i + 1], cows[i][0]);
        sufMaxX[i] = max(sufMaxX[i + 1], cows[i][0]);
        sufMinY[i] = min(sufMinY[i + 1], cows[i][1]);
        sufMaxY[i] = max(sufMaxY[i + 1], cows[i][1]);
    }

    xMin = cows[0][0], xMax = cows[0][0], yMin = cows[0][1], yMax = cows[0][1]; 
    
    for (int i = 0; i < n - 1; i++) {
        xMin = min(xMin, cows[i][0]);
        xMax = max(xMax, cows[i][0]);
        yMin = min(yMin, cows[i][1]);
        yMax = max(yMax, cows[i][1]);
        if (xMax == sufMinX[i + 1] && yMax >= sufMinY[i + 1]) continue;
        ans = min(ans, (xMax - xMin) * (yMax - yMin) + (sufMaxX[i + 1] - sufMinX[i + 1]) * (sufMaxY[i + 1] - sufMinY[i + 1]));
    }

    cout << originalArea - ans << '\n';

    return 0;
}
