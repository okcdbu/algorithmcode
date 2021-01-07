#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[2][100001];
int sticker[2][100001];
int main() {
	ifstream fp1("stickers.inp");
	ofstream fp2("stickers.out");

	int T;
	fp1 >> T;
	while (T--) {
		int n;
		fp1 >> n;
		for (int i = 0; i < n; i++) {
			fp1 >> sticker[0][i];
		}
		for (int i = 0; i < n; i++) {
			fp1 >> sticker[1][i];
		}
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = max(dp[0][0], max(dp[1][0] + sticker[0][1], sticker[0][1]));
		dp[1][1] = max(dp[1][0], max(dp[0][0] + sticker[1][1], sticker[1][1]));
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1]+ sticker[0][i], dp[1][i - 2] + sticker[0][i]));
			dp[1][i] = max(dp[1][i - 1], max(dp[0][i - 1]+ sticker[1][i], dp[0][i - 2] + sticker[1][i]));
		}
		fp2 << max(dp[1][n - 1], dp[0][n - 1]) << endl;
	}
}