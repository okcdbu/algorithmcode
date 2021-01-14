#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;
//int isvisit[1001][1001];
int arr[1001][1001];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int answer;
queue<pair<int, int>> rq;
int N,M;
void bfs() {
	
	int x, y;
	
	while (!rq.empty()) {
		x = rq.front().first;
		y = rq.front().second;
		rq.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] != 0)
				continue;
			rq.push({ nx,ny });
			arr[nx][ny] = arr[x][y] + 1;
		}
	}
	answer = arr[N - 1][M - 1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	answer = -INF;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				rq.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << '\n';
				exit(0);
			}
			answer = max(answer, arr[i][j]);
		}
	}
	answer--;
	cout << answer << '\n';
		
}