#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;
bool isvisit[51][51];
int arr[51][51];
int answer = 0;
int N,M;
void dfs(int col,int row) {
	if (arr[col][row] == 0 || isvisit[col][row] || row >= N || col >= M || row < 0 || col < 0)
		return;
	isvisit[col][row] = true;
	dfs(col - 1, row);
	dfs(col + 1, row);
	dfs(col, row + 1);
	dfs(col, row - 1);
	dfs(col + 1, row + 1);
	dfs(col - 1, row - 1);
	dfs(col - 1, row + 1);
	dfs(col + 1, row - 1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		answer = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!isvisit[i][j] && arr[i][j] == 1) {
					dfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << '\n';
		memset(isvisit, 0, sizeof(isvisit));
	}
	
}