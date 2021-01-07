#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int N;

int arr[13];
vector<int> basic;

void dfs(int idx) {
	
	if (basic.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << basic[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < N; i++) {
		basic.push_back(arr[i]);
		dfs(i + 1);
		basic.pop_back();
	}
}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> N;
		if (!N)
			break;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		dfs(0);
		basic.clear();
		cout << '\n';
	}
	
	
}