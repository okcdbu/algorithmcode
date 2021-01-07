#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Edge {
public:
	int xval;
	int yval;
	bool isX;
};

class Map {
public:
	int cost;
	int count;
};
ifstream fp1("path.inp");
ofstream fp2("path.out");
Map dp[100][100][201];
Edge weight[100][100];
vector<pair<int, int>> answer;
void finder(int i, int j, int k) {
	answer.push_back({ i,j });
	if (i == 0 && j == 0)
		return;
	int temp = k;
	if (weight[i][j].isX)
		temp--;
	if (dp[i][j -1][temp].cost + weight[i][j - 1].xval==dp[i][j][k].cost) {
		finder(i, j - 1, temp);
	}
	else {
		finder(i - 1, j, temp);
	}

}
int main() {
	
	int T;
	fp1 >> T;
	for (int z = 0; z < T;z++) {
		int M, N, K;
		fp1 >> M >> N >> K;
		memset(weight, 0, sizeof(weight));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < K; i++) {
			int x, y;
			fp1 >> x >> y;
			weight[x][y].isX = true;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N - 1; j++) {
				fp1 >> weight[i][j].xval;
			}
		}
		for (int i = 0; i < M-1; i++) {
			for (int j = 0; j < N; j++) {
				fp1 >> weight[i][j].yval;
			}
		}
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k <= K; k++) {
					dp[i][j][k].cost = 999999999;
					dp[i][j][k].count = 0;
				}
			}
		}
		dp[0][0][0].cost = 0;
		dp[0][0][0].count = 1;
		int k = 0;
		for (int i = 1; i < M; i++) {
			if (weight[i][0].isX) {
				dp[i][0][k + 1].cost = dp[i - 1][0][k].cost + weight[i - 1][0].yval;
				k++;
			}
			else
				dp[i][0][k].cost = dp[i - 1][0][k].cost + weight[i - 1][0].yval;
			dp[i][0][k].count = 1;
		}
		k = 0;
		for (int j = 1; j < N; j++) {
			if (weight[0][j].isX) {
				dp[0][j][k+1].cost = dp[0][j-1][k].cost + weight[0][j - 1].xval;
				k++;
			}
			else {
				dp[0][j][k].cost = dp[0][j-1][k].cost + weight[0][j - 1].xval;
			}
			dp[0][j][k].count = 1;
		}
		for (int i = 1; i < M; i++) {
			for (int j = 1; j < N; j++) {
				for (int k = 0; k <= K; k++) {
					if (weight[i][j].isX) {
						dp[i][j][k + 1].cost = min(dp[i - 1][j][k].cost + weight[i - 1][j].yval, dp[i][j - 1][k].cost + weight[i][j - 1].xval);
						dp[i][j][k + 1].count = (dp[i - 1][j][k].count % 100000 + dp[i][j - 1][k].count % 100000) % 100000;
					}
						
					else {
						dp[i][j][k].cost = min(dp[i - 1][j][k].cost + weight[i - 1][j].yval, dp[i][j - 1][k].cost + weight[i][j - 1].xval);
						dp[i][j][k].count = (dp[i - 1][j][k].count % 100000 + dp[i][j - 1][k].count % 100000) % 100000;
					}
						
					
				}
			}
		}
		fp2 << "Test Case No:" << z + 1 << endl;
		for (int p = 0; p <= K; p++) {
			//
			if (dp[M - 1][N - 1][p].cost < 999999999 && dp[M - 1][N - 1][p].count > 0) {
				finder(M - 1, N - 1, p);
				fp2 << "k:" << p << " count:" << dp[M - 1][N - 1][p].count << " cost:" << dp[M - 1][N - 1][p].cost << endl;
				while (!answer.empty()) {
					fp2 << "(" << answer.back().first << "," << answer.back().second << ")";
					answer.pop_back();
					if (!answer.empty())
						fp2 << "->";
				}
				fp2 << endl;
				answer.clear();
			}
		}
		fp2 << endl;
	}
}