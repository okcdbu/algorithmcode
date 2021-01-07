#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
bool dp[4][101][101][101];

int main() {
	ifstream fp1("coin.inp");
	ofstream fp2("coin.out");
	dp[0][0][0][0] = true;
	dp[1][0][0][0] = true;
	dp[2][0][0][0] = true;
	dp[3][0][0][0] = true;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				if (i == 0 && j == 0 && k == 0)
					continue;

				dp[1][i][j][k] = !(i - 2 < 0 ? true : dp[2][i - 2][j][k]) || !(i - 3 < 0 ? true : dp[3][i - 3][j][k]) || !(j - 2 < 0 ? true : dp[2][i][j - 2][k])
					|| !(j - 3 < 0 ? true : dp[3][i][j - 3][k]) || !(k - 2 < 0 ? true : dp[2][i][j][k - 2]) || !(k - 3 < 0 ? true : dp[3][i][j][k - 3]);
				dp[2][i][j][k] = !(i - 1 < 0 ? true : dp[1][i - 1][j][k]) || !(i - 3 < 0 ? true : dp[3][i - 3][j][k]) || !(j - 1 < 0 ? true : dp[1][i][j - 1][k])
					|| !(j - 3 < 0 ? true : dp[3][i][j - 3][k]) || !(k - 1 < 0 ? true : dp[1][i][j][k - 1]) || !(k - 3 < 0 ? true : dp[3][i][j][k - 3]);
				dp[3][i][j][k] = !(i - 2 < 0 ? true : dp[2][i - 2][j][k]) || !(i - 1 < 0 ? true : dp[1][i - 1][j][k]) || !(j - 2 < 0 ? true : dp[2][i][j - 2][k])
					|| !(j - 1 < 0 ? true : dp[1][i][j - 1][k]) || !(k - 2 < 0 ? true : dp[2][i][j][k - 2]) || !(k - 1 < 0 ? true : dp[1][i][j][k - 1]);
				dp[0][i][j][k] = dp[1][i][j][k] || dp[2][i][j][k] || dp[3][i][j][k];
			}
		}
	}
	int T;
	fp1 >> T;
	while (T--) {
		int c1, c2, c3;
		fp1 >> c1 >> c2 >> c3;
		
		fp2 << "(" << c1 << " " << c2 << " " << c3 << ") : ";
		if (dp[0][c1][c2][c3])
			fp2 << 1 << endl;
		else
			fp2 << -1 << endl;
		//memset(dp, 0, sizeof(dp));
	}
}