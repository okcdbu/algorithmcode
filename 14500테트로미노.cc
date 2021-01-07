#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int map[500][500];
int tetromino[19][4][2] = {
	// ㅡ 블럭
	
		// 첫번째 방향
		{ {0,0},{0,1},{0,2},{0,3} },
		// 두번째 방향
		{ {0,0},{1,0},{2,0},{3,0} },

	// ㅁ 블럭
	
		// 첫번째 방향
		{ {0,0},{0,1},{1,0},{1,1} },
	
	// ㄴ 블럭
	
		// 첫번째 방향
		{ {0,0},{1,0},{2,0},{2,1} },
		// 두번째 방향
		{ {0,0},{0,1},{0,2},{1,0} },
		// 세번째 방향
		{ {0,0},{0,1},{1,1},{2,1} },
		// 네번째 방향
		{ {0,0},{0,1},{0,2},{-1,2} },
	
	// ㄴ 블럭 (대칭)

		// 첫번째 방향
		{ {0,0},{0,1},{-1,1},{-2,1} },
		// 두번째 방향
		{ {0,0},{1,0},{1,1},{1,2} },
		// 세번째 방향
		{ {0,0},{0,1},{1,0},{2,0} },
		// 네번째 방향
		{ {0,0},{0,1},{0,2},{1,2} },

	// ㄴㄱ 블럭
		// 첫번째 방향
		{ {0,0},{1,0},{1,1},{2,1} },
		// 두번째 방향
		{ {0,0},{0,1},{-1,1},{-1,2} },
		// 세번째 방향
		{ {0,0},{1,0},{1,-1},{2,-1} },
		// 네번째 방향
		{ {0,0},{0,1},{1,1},{1,2} },

	// ㅗ 블럭
		// 첫번째 방향
		{ {0,0},{0,-1},{0,1},{-1,0} },
		// 두번째 방향
		{ {0,0},{-1,0},{1,0},{0,1} },
		// 세번째 방향
		{ {0,0},{0,-1},{0,1},{1,0} },
		// 네번째 방향
		{ {0,0},{-1,0},{1,0},{0,-1} }
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int answer = -INF;
	int sum = 0;
	int nx = 0, ny = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				sum = 0;
				bool breakpoint = false;
				for (int l = 0; l < 4; l++) {
					nx = i + tetromino[k][l][0];
					ny = j + tetromino[k][l][1];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
						breakpoint = true;
						break;
					}
					sum += map[nx][ny];
				}
				if (breakpoint)
					continue;
				answer = max(answer, sum);
			}
		}
	}
	cout << answer;
}