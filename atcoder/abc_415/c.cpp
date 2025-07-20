#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

bool ans;
int c;
long long mix;
std::string s;

void solve(long long numero) {
    if (ans) {
        return;
    }
    
    if (numero == 0) {
        ans = true;
        return;
    }

    for (int i = 0; i < c; ++i) {
        if ((numero & (1LL << i)) != 0) {
            long long temp = numero & ~(1LL << i);

            if (temp > 0 && s[temp - 1] == '1') {
                continue;
            }
            
            solve(temp);
        }
    }
}

void run_test_case() {
    ans = false;
    std::cin >> c;

    mix = (1LL << c) - 1;

    std::cin >> s;

    if (s[((int) s.size()) - 1] == '1') {
        std::cout << "No\n";
        return;
    }

    bool every = true;
    for (int i = 0; i < c; i++) {
        if (s[(1 << i) - 1] == '0') {
            every = false;
            break;
        }
    }

    if (every) {
        std::cout << "No\n";
        return;
    }

    solve(mix);

    if (ans) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        run_test_case();
    }

    return 0;
}