#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, S,cnt = 0;
int arr[21];

void sumofsubset(int i, int weight) {

	if (i >= N) {
		return;
	}
	if (weight + arr[i] == S)
		cnt++;
	sumofsubset(i + 1, weight + arr[i]);
	sumofsubset(i + 1, weight);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int total = 0;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sumofsubset(0,0);
	cout << cnt << '\n';
	
}