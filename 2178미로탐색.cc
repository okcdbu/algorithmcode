#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;
int isvisit[101][101];
char arr[101][101];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int answer;
int N,M;
void bfs(int col,int row) {
	queue<pair<int, int>> rq;
	rq.push({ col,row });
	int x, y;
	isvisit[col][row] = 1;
	while (!rq.empty()) {
		x = rq.front().first;
		y = rq.front().second;
		rq.pop();
		if (x == N - 1 && y == M - 1)
			break;
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == '0' || isvisit[nx][ny] > 0)
				continue;
			rq.push({ nx,ny });
			isvisit[nx][ny] = isvisit[x][y] + 1;
		}
	}
	answer = isvisit[N - 1][M - 1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	
	cin >> N >> M;
	answer = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs(0, 0);
	cout << answer << '\n';
		
}