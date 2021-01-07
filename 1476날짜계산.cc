#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int E, S, M;
	int year = 1;
	cin >> E >> S >> M;
	while (true) {
		if ((year - 1) % 15 + 1 == E && (year - 1) % 28 + 1 == S && (year - 1) % 19 + 1 == M) {
			cout << year;
			break;
		}
		year++;
	}
}