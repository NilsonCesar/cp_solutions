#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios_base::sync_with_stdio(0);

int id = 2, monarchy = 1;
vector<bool> dead(1e5+7, false); 
vector<int> childs_explored(1e5+7, 0), parent(1e5+7);
vector<vector<int>> g;

int main() {_
    int q, t, x;
    cin >> q;
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    parent[1] = 1;

    while(q--) {
        cin >> t >> x;
        if (t == 1) {
            g[x].push_back(id);
            parent[id] = x;
            g.push_back(vector<int>());
            id++;
        } else {
            dead[x] = true;
            while(dead[monarchy]) {
                if (childs_explored[monarchy] < g[monarchy].size()) {
                    childs_explored[monarchy]++;
                    monarchy = g[monarchy][childs_explored[monarchy] - 1];
                } else {
                    monarchy = parent[monarchy];
                }
            }
            cout << monarchy << '\n';
        }
    }

    return 0;
}