#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int index = -1;
	for (int i = N - 1; i >= 1; i--) {
		if (arr[i - 1] < arr[i]) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << index;
	}
	else {
		for (int i = N - 1; i >= index; i--) {
			if (arr[index - 1] < arr[i]) {
				swap(arr[index - 1], arr[i]);
				break;
			}
		}
		sort(arr + index, arr + N);
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " " ;
		}
	}
}