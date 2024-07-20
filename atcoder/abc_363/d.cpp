#include <bits/stdc++.h>

using namespace std;

long long ten(int x) { return x == 0 ? 1 : ten(x - 1) * 10;  }

int main(void) {
	long long n;
	cin >> n;
	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	
	n--;

	for(int i = 1; ; i++) {
		int x = (i + 1) / 2;
		
		if(n <= 9 * ten(x - 1)) {
			string s = to_string(ten(x - 1) + n - 1);
			s.resize(i, ' ');
			for(int j = x; j < i; j++) s[j] = s[i - 1 - j];
			cout << s << '\n';
			return 0;
		} else {
			n -= 9 * ten(x - 1);
		}
	}
}

