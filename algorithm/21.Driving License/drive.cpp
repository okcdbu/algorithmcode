#include <iostream>
#include <fstream>
#include <algorithm>
typedef struct Map {
	int right;
	int down;
};

using namespace std;
Map map[101][101];
int dp[101][101][204][2];

int main() {
	ifstream fp1("drive.inp");
	ofstream fp2("drive.out");

	int T;
	fp1 >> T;
	while (T--) {
		int M, N, L, G;
		fp1 >> M >> N >> L >> G;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N - 1; j++) {
				fp1 >> map[i][j].right;
			}
		}
		for (int i = 0; i < M-1; i++) {
			for (int j = 0; j < N; j++) {
				fp1 >> map[i][j].down;
			}
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k <= N + M; k++) {
					for (int l = 0; l < 2; l++) {
						dp[i][j][k][l] = 999999999;
					}
				}
			}
		}
		dp[0][0][0][0] = 0;
		dp[0][0][0][1] = 0;
		for (int k = 1; k < N; k++) {
			dp[0][k][0][0] = dp[0][k - 1][0][0] + map[0][k - 1].right;
		}
		for (int k = 1; k < M; k++) {
			dp[k][0][0][1] = dp[k - 1][0][0][1] + map[k - 1][0].down;
		}
		
		for (int i = 1; i < M; i++) {
			for (int j = 1; j < N; j++) {
				for (int k = 1; k <= M + N; k++) {
					dp[i][j][k][0] = min(dp[i][j - 1][k][0] + map[i][j - 1].right, dp[i][j - 1][k - 1][1] + map[i][j - 1].right);
					dp[i][j][k][1] = min(dp[i-1][j][k][1] + map[i-1][j].down,dp[i-1][j][k-1][0] + map[i-1][j].down);
				}
			}
		}
		int answer = -1;
		for (int k = 0; k <= N + M; k++) {
			if (dp[M - 1][N - 1][k][0] <= G || dp[M - 1][N - 1][k][1] <= G) {
				answer = L * (N + M - 2) + k;
				break;
			}
		}
		fp2 << answer << endl;
	}
}