#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;
bool isvisit[26][26];
char arr[26][26];
int answer = 0;
int N;
int num[625];
void dfs(int col,int row) {
	if (arr[col][row] == '0' || isvisit[col][row] || row >= N || col >= N || row < 0 || col < 0)
		return;
	isvisit[col][row] = true;
	num[answer]++;
	dfs(col - 1, row );
	dfs(col + 1, row);
	dfs(col, row + 1);
	dfs(col, row - 1);
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isvisit[i][j] && arr[i][j] == '1') {
				dfs(i, j);
				answer++;
			}
		}
	}
	cout << answer << '\n';
	sort(num, num + answer);
	for (int i = 0; i < answer; i++) {
		cout << num[i] << '\n';
	}
}