#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#define colSize 1004
using namespace std;
ifstream fp1("watertank.inp");
ofstream fp2("watertank.out");
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int hole[1004][1004][4], height[1004][1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	int T;
	int N, M, H, answer, buf;
	fp1 >> T;
	while (T--) {
		fp1 >> N >> M >> H;
		answer = 0;
		for (int i = 1; i <=N + 1; i++) {
			for (int j = 1; j <= M; j++) {
				fp1 >> buf;
				hole[i - 1][j][2] = buf;//�Ʒ������� ������
				hole[i][j][0] = buf;//�������� �Ʒ�����
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M + 1; j++) {
				fp1 >> buf;
				hole[i][j - 1][1] = buf;//���ʱ����� ��������
				hole[i][j][3] = buf;//�����ʱ����� �޹���
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				height[i][j] = H;//���̰�
			}
		}
		for (int i = 0; i <= N + 1; i++) {
			if (hole[i][0][1] != -1) {//���� �����
				if (height[i][1] > hole[i][0][1]) {
					height[i][1] = hole[i][0][1];
					pq.push({ hole[i][0][1], colSize * i + 1 });
				}
			}
			if (hole[i][M + 1][3] != -1) {
				if (height[i][M] > hole[i][M + 1][3]) {
					height[i][M] = hole[i][M + 1][3];
					pq.push({ hole[i][M + 1][3], colSize * i + M });
				}
			}
		}

		for (int i = 0; i <= M + 1; i++) {
			if (hole[0][i][2] != -1) {
				if (height[1][i] > hole[0][i][2]) {
					height[1][i] = hole[0][i][2];
					pq.push({ hole[0][i][2], colSize + i });
				}
			}
			if (hole[N + 1][i][0] != -1) {
				if (height[N][i] > hole[N + 1][i][0]) {
					height[N][i] = hole[N + 1][i][0];
					pq.push({ hole[N + 1][i][0], colSize * N + i });
				}
			}
		}

		while (!pq.empty()) {//���ͽ�Ʈ��
			int y = pq.top().second / colSize;//y�� �޾ƿ���
			int x = pq.top().second % colSize;//x�� �޾ƿ���
			int nh = pq.top().first;
			pq.pop();
			if (height[y][x] != nh)
				continue;
			for (int i = 0; i < 4; i++) {
				if (hole[y][x][i] == -1) 
					continue;
				int ny = y + dy[i];
				int nx = x + dx[i];
				if ((ny < 1 || ny > N )|| (nx < 1 || nx > M)) 
					continue;

				int tmph = max(height[y][x], min(hole[y][x][i], height[ny][nx]));
				if (height[ny][nx] > tmph) {
					height[ny][nx] = tmph;
					pq.push({ tmph, colSize * ny + nx });
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				answer += height[i][j];
			}
		}
		fp2 << answer << endl;
	}
}