#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int N;
int ans;
vector<int> arr;
int basic[9];
bool isvisited[9];
void dfs(int num) {
	arr.push_back(num);
	if (arr.size() == N) {
		int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += abs(arr[i - 1] - arr[i]);
		}
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (isvisited[i]) continue;
		isvisited[i] = true;
		dfs(basic[i]);
		isvisited[i] = false;
		arr.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	ans = -INF;
	for (int i = 1; i <= N; i++) {
		cin >> basic[i];
	}
	for (int i = 1; i <= N; i++) {
		isvisited[i] = true;
		dfs(basic[i]);
		isvisited[i] = false;
		arr.pop_back();
	}
	cout << ans;
}