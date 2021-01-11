#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;

int N,M,start;
vector<int> arr[1001];
vector<int> answer;
bool endflag;
bool isvisit[1001];
vector<int> rq;
void dfs(int number,int cnt) {
	isvisit[number] = true;
	answer.push_back(number);
	cout << number << " ";
	
	for (int i = 0; i < arr[number].size(); i++) {
		if (endflag) return;
		if (isvisit[arr[number][i]])continue;
		dfs(arr[number][i], cnt + 1);
	}
	
}
void bfs() {
	rq.push_back(start);
	isvisit[start] = true;
	while (!rq.empty()) {
		int number = rq.front();
		rq.erase(rq.begin());
		cout << number << " ";
		for (int i = 0; i < arr[number].size(); i++) {
			if (isvisit[arr[number][i]])continue;
			isvisit[arr[number][i]] = true;
			rq.push_back(arr[number][i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	cin >> N >> M >> start;
	int tmp,tmp2;
	for (int i = 0; i < M; i++) {
		cin >> tmp >> tmp2;
		arr[tmp].push_back(tmp2);
		arr[tmp2].push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	dfs(start, 1);
	cout << "\n";
	memset(isvisit, false, sizeof(isvisit));
	bfs();
}