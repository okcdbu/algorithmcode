#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
bool isanswer[10];
bool iscome;
void print() {
	int cnt = 0;
	if (iscome)
		return;
	for (int i = 0; i < 9; i++) {
		if (isanswer[i]) {
			cnt++;
		}
	}
	if (cnt != 7)
		return;
	iscome = true;
	for (int i = 0; i < 9; i++) {
		if (isanswer[i]) {
			cout << arr[i] << '\n';
		}
	}
}
bool ispromising(int i, int weight, int total) {
	if ((weight + total >= 100) && (100 == weight || weight + arr[i + 1] <= 100)) {
		return true;
	}
	else
		return false;
}
void sumofsubset(int weight, int i, int total) {
	if (ispromising(i, weight, total)) {
		if (weight == 100) {
			print();
			return;
		}
		isanswer[i + 1] = true;
		sumofsubset(weight + arr[i + 1], i + 1, total - arr[i + 1]);
		isanswer[i + 1] = false;
		sumofsubset(weight, i + 1, total - arr[i + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 9;
	while (T--) {
		cin >> arr[8 - T];
	}
	int total = 0;
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		total += arr[i];
	}
	sumofsubset(0, -1, total);
}