#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int N;
int arr[101];
int op[4];//0 + 1 - 2 * 3 /
vector<int> basic;
int maxval = -INF, minval = INF;
void dfs(int plus, int minus, int multi, int divide, int cnt, int sum) {
	if (cnt == N) {
		maxval = max(maxval, sum);
		minval = min(minval, sum);
		return;
	}
	if (plus > 0) {
		dfs(plus - 1, minus, multi, divide, cnt + 1, sum + arr[cnt]);
	}
	if (minus > 0) {
		dfs(plus, minus - 1, multi, divide, cnt + 1, sum - arr[cnt]);
	}
	if (multi > 0) {
		dfs(plus, minus, multi - 1, divide, cnt + 1, sum * arr[cnt]);
	}
	if (divide > 0) {
		dfs(plus, minus, multi, divide - 1, cnt + 1, sum / arr[cnt]);
	}
}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(op[0], op[1], op[2], op[3], 1, arr[0]);
	cout << maxval << '\n' << minval << '\n';
}