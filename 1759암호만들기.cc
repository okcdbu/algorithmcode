#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int L,C;
char arr[15];
int answer = 0;
void dfs(int idx, int cnt, int cons,int vow, vector<char> str) {
	if (cnt == L) {
		if (cons >= 2 && vow >= 1) {
			for (int i = 0; i < str.size(); i++)
				cout << str[i];
			cout << '\n';
		}
		return;
	}
	if (idx == C)
		return;
	if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u') {
		str.push_back(arr[idx]);
		dfs(idx + 1, cnt + 1, cons, vow + 1, str);
		str.pop_back();
	}
	else {
		str.push_back(arr[idx]);
		dfs(idx + 1, cnt + 1, cons + 1, vow, str);
		str.pop_back();
	}
	dfs(idx + 1, cnt, cons, vow, str);
		
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;
	char buf;
	int cnt = 0;
	for (int i = 0; i < C; i++) {
		cin >> buf;
		if (buf >= 'a' && buf <= 'z') {
			arr[cnt++] = buf;
		}
	}
	sort(arr, arr + C);
	vector<char> tmp;
	dfs(0, 0, 0, 0, tmp);

	
}