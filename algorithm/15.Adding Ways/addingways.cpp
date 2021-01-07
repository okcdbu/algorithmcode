#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[301][21];
int main() {
	ifstream fp1("addingways.inp");
	ofstream fp2("addingways.out");
	while (true) {
		int n, k;
		fp1 >> n >> k;
		if (n == 0 && k == 0)
			break;
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (i == 0 || j == 0 || i < j)
					dp[i][j] = 0;
				else if (j == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = (dp[i - 1][j - 1] % 1000000007 + dp[i - j][j] % 1000000007) % 1000000007;
			}
		}
		fp2 << dp[n][k] << endl;
	}
}