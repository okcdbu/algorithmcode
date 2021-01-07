#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
typedef struct Coordinate {
	long long int x, y;
};
typedef struct Line {
	long long int distance;
	Coordinate Center;
	int first, second;
};
Coordinate arr[1001];
Line line[1002001];
bool sortLineByDistance(Line A, Line B) {
	if (A.distance != B.distance) {
		return A.distance < B.distance;
	}
	else if (A.Center.x != B.Center.x) {
		return A.Center.x < B.Center.x;
	}
	else
		return A.Center.y < B.Center.y;
}
long long int getSize(Coordinate A, Coordinate B, Coordinate C, Coordinate D) {
	return (abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) + abs(A.x * (B.y - D.y) + B.x * (D.y - A.y) + D.x * (A.y - B.y)))/2;
}
int main() {
	ifstream fp1("rectangle.inp");
	ofstream fp2("rectangle.out");

	int T;
	fp1 >> T;
	while (T--) {
		int n;
		long long int idx = 0, answer = 0;
		fp1 >> n;
		for (int i = 0; i < n; i++) {
			fp1 >> arr[i].x >> arr[i].y;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				line[idx].distance = (arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y);//거리의 제곱
				line[idx].Center.x = (arr[i].x + arr[j].x) / 2;//중점 x좌표
				line[idx].Center.y = (arr[i].y + arr[j].y) / 2;//중점 y좌표
				line[idx].first = i;//대각선 시작점의 인덱스
				line[idx].second = j;//대각선 끝점의 인덱스
				idx++;
			}
		}
		sort(line, line + idx, sortLineByDistance);
		for (int i = 0; i < idx; i++) {
			for (int j = i + 1; line[i].distance == line[j].distance && line[i].Center.x == line[j].Center.x && line[i].Center.y == line[j].Center.y; j++) {//
				answer = max(answer, getSize(arr[line[i].first], arr[line[i].second], arr[line[j].first], arr[line[j].second]));
			}
		}
		fp2 << answer << endl;

	}
}