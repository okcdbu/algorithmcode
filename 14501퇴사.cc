#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int N;
int T[15],P[15];
int answer = -INF;
void dfs(int time,int profit) {
	if (time > N)
		return;
	answer = max(answer, profit);
	if (time >= N)
		return;
	dfs(time + T[time], profit + P[time]);
	dfs(time + 1, profit);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	dfs(0,0);
	cout << answer << '\n';
}