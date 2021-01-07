#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int, int>> arr[501];
vector<int> path[501];
double contactpt;
int cost[501];
pair<int, int> query[3];
pair<int, int> ans = { 999999999,999999999 };
void findMinByDijkstra(int start) {
	cost[start] = 0;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > minheap;
	minheap.push({ 0, start });
	while (!minheap.empty()) {
		int now = minheap.top().second;
		int distance = minheap.top().first;
		minheap.pop();
		if (cost[now] < distance)
			continue;
		else
			for (int i = 0; i < arr[now].size(); i++) {
				int next = arr[now][i].second;
				if (distance + arr[now][i].first < cost[next]) {
					cost[next] = distance + arr[now][i].first;
					minheap.push({ distance + arr[now][i].first, next });
					path[next].clear();
					path[next].push_back(now);
				}
				else if (distance + arr[now][i].first == cost[next]) {
					path[next].push_back(now);
				}
			}
	}
}
void dfs(int start, int end, int distance, int total) {
	
	if (distance > contactpt) {
		if (start > end)
			swap(start, end);
		if (ans.first > start) {
			ans = { start,end };
		}
		else if (ans.first == start) {
			if (ans.second > end) {
				ans = { start,end };
			}
		}
		return;
	}
	else if (distance == contactpt) {
		if (ans.first > start) {
			ans = { start,end };
		}
		return;
	}
	for (int i = 0; i < path[start].size(); i++) {
		dfs(path[start][i], start, total - cost[path[start][i]],total);
	}
}
int main() {
	ifstream fp1("contact.inp");
	ofstream fp2("contact.out");

	int T;
	fp1 >> T;
	while (T--) {
		int N, M, K;
		fp1 >> N >> M >> K;
		for (int i = 1; i < 501; i++) {
			cost[i] = 999999999;
			path[i].clear();
			arr[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			int idx, ep, weight;
			fp1 >> idx >> ep >> weight;
			arr[idx].push_back({ weight, ep });
			arr[ep].push_back({ weight, idx });
		}

		for (int i = 0; i < K; i++) {
			fp1 >> query[i].first >> query[i].second;
			findMinByDijkstra(query[i].first);
			contactpt = cost[query[i].second] / 2.0;
			dfs(query[i].second, 0,0,cost[query[i].second]);
			fp2 << ans.first << " " << ans.second << endl;
			ans = { 999999999, 999999999 };
			for (int i = 1; i < 501; i++) {
				cost[i] = 999999999;
				path[i].clear();
			}
		}

	}
}