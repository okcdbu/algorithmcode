#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int N;
int weight[10][10];
int dp[10][1 << 10];
int TSP(int current, int visited) {
	if (visited == (1 << N) - 1) {
		if (weight[current][0] > 0)
			return weight[current][0];
		else
			return INF;
	}
	if (dp[current][visited] != -1)
		return dp[current][visited];
	int val = INF;
	for (int i = 0; i < N; i++) {
		if (weight[current][i] == 0 || (visited & (1 << i))) {
			continue;
		}
		val = min(val, TSP(i, visited | (1 << i)) + weight[current][i]);
	}
	dp[current][visited] = val;
	return val;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	int ret = TSP(0, 1);
	cout << ret << '\n';
}