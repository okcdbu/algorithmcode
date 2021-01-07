#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int N;
int answer = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	while (N--) {
		string str;
		int x;
		cin >> str;
		if (str == "add") {
			cin >> x;
			answer |= 1 << x;
		}
		else if (str == "remove") {
			cin >> x;
			answer &= ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;
			if (answer & (1 << x)) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle") {
			cin >> x;
			answer ^= 1 << x;
		}
		else if (str == "all") {
			answer = (1 << 21) - 1;
		}
		else if (str == "empty") {
			answer = 0;
		}
	}
	
}