#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
bool isvisit[9];
vector<int> answer;
int N,M;
void dfs(int number,int cnt) {
	answer.push_back(number);
	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << answer[i - 1] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (isvisit[i])continue;
		isvisit[i] = true;
		dfs(i, cnt + 1);
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
		isvisit[i] = true;
		dfs(i, 1);
		isvisit[i] = false;
		answer.pop_back();
	}
}