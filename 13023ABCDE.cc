#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
bool answer,isvisited[2001];
int N,M;
vector<int> friendlist[2001];
void dfs(int idx,int cnt) {
	if (cnt == 4) {
		cout << 1 << '\n';
		exit(0);
	}
	isvisited[idx] = true;
	for (int i = 0; i < friendlist[idx].size(); i++) {
		if (isvisited[friendlist[idx][i]])continue;
		dfs(friendlist[idx][i], cnt + 1);
	}
	isvisited[idx] = false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int M1, M2;
		cin >> M1 >> M2;
		friendlist[M1].push_back(M2);
		friendlist[M2].push_back(M1);
	}
	for (int i = 0; i < N; i++) {
		memset(isvisited, 0, sizeof(isvisited));
		dfs(i, 0);
	}
	cout << 0 << '\n';
}