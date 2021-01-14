#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;
//int isvisit[1001][1001];
int arr[100001];
//int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int answer;
int N,K;
void bfs(int i) {
	queue<int> rq;
	rq.push(i);
	arr[i] = 0;
	answer = 0;
	while (!rq.empty()) {
		int x = rq.front();
		rq.pop();
		if (x == K) {
			answer = arr[x];
			break;
		}
		if (x > 0 && arr[x - 1] == 0) {
			arr[x - 1] = arr[x] + 1;
			rq.push(x - 1);
		}
		if (x + 1 <= K && arr[x + 1] == 0) {
			arr[x + 1] = arr[x] + 1;
			rq.push(x + 1);
		}
		if (2 * x <= K + 1 && arr[2 * x] == 0) {
			arr[x * 2] = arr[x] + 1;
			rq.push(x * 2);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	answer = INF;
	cin >> N >> K;
	
	bfs(N);
	
	cout << answer << '\n';
		
}