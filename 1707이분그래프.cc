#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;
int colorarr[20001];
vector<int> Edge[20001];
int N, M;
bool isBiparti = true;
void dfs(int number, int color) {
	colorarr[number] = color;
	for (int i = 0; i < Edge[number].size(); i++) {
		if (color == colorarr[Edge[number][i]] || !isBiparti) {
			isBiparti = false;
			return;
		}
		else if(colorarr[Edge[number][i]] == 0){
			dfs(Edge[number][i], -color);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int tmp, tmp2;
		for (int i = 0; i < M; i++) {
			cin >> tmp >> tmp2;
			Edge[tmp].push_back(tmp2);
			Edge[tmp2].push_back(tmp);
		}
		for (int i = 1; i <= N; i++) {
			if (!colorarr[i]) {
				dfs(i, 1);
			}
		}
		cout << (isBiparti ? "YES" : "NO") << "\n";
		for (int i = 1; i <= N; i++) {
			Edge[i].clear();
		}
		memset(colorarr, 0, sizeof(colorarr));
		isBiparti = true;
	}
}