#include <iostream>
using namespace std;
int DP[11];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;
		for (int i = 4; i <= n; i++) {
			DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
		}
		cout << DP[n] << '\n';
	}
	
}