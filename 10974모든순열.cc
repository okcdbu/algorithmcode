#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int N;
vector<int> arr;
bool isvisited[9];
void dfs(int num) {
	arr.push_back(num);
	if (arr.size() == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (isvisited[i]) continue;
		isvisited[i] = true;
		dfs(i);
		isvisited[i] = false;
		arr.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		isvisited[i] = true;
		dfs(i);
		isvisited[i] = false;
		arr.pop_back();
	}
}