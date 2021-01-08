#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
bool isvisit[9];
int arr[9];
vector<int> answer;
int N,M;
void dfs(int number,int cnt, int idx) {
	answer.push_back(number);
	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << answer[i - 1] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx + 1; i <= N; i++) {
		if (isvisit[i])continue;
		isvisit[i] = true;
		dfs(arr[i], cnt + 1 , i);
		isvisit[i] = false;
		answer.pop_back();
	}
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		isvisit[i] = true;
		dfs(arr[i], 1 , i);
		isvisit[i] = false;
		answer.pop_back();
	}
}