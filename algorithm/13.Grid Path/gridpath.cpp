#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int memo[200][200], map[200][200];
int main() {
	ifstream fp1("gridpath.inp");
	ofstream fp2("gridpath.out");

	int n, m;

	vector<pair<int, int>> direction;
	fp1 >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fp1 >> map[i][j];
		}
	}
	bool isblock = false;
	memo[0][0] = map[0][0];
	for (int i = 1; i < n; i++) {
		if (map[i][0] == -1) {
			isblock = true;
			memo[i][0] = -1;
			continue;
		}
		int addition = isblock ? -1 : memo[i-1][0] + map[i][0];
		memo[i][0] = addition;
	}
	isblock = false;
	for (int i = 1; i < m; i++) {
		if (map[0][i] == -1) {
			isblock = true;
			memo[0][i] = -1;
			continue;
		}
		int addition = isblock ? -1 : memo[0][i-1] + map[0][i];
		memo[0][i] = addition;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (map[i][j] == -1) {
				memo[i][j] = -1;
				continue;
			}
			if (memo[i][j - 1] == -1 && memo[i - 1][j] == -1) {
				memo[i][j] = -1;
			}
			else if (memo[i][j - 1] == -1) {
				memo[i][j] = memo[i - 1][j] + map[i][j];
			}
			else if (memo[i - 1][j] == -1) {
				memo[i][j] = memo[i][j - 1] + map[i][j];
			}
			else {
				memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + map[i][j];
			}
		}
	}
	int i = n - 1, j = m - 1;
	while (true) {
		direction.push_back(make_pair(i, j));
		if (i == 0 && j == 0)
			break;
		else if (i == 0) {
			j--;
		}
		else if (j == 0) {
			i--;
		}
		else {
			if (memo[i][j - 1] == -1) {
				i--;
			}
			else if (memo[i - 1][j] == -1) {
				j--;
			}
			else if (memo[i][j - 1] >= memo[i - 1][j])
				i--;
			else
				j--;
		}
	}
	if (memo[n - 1][m - 1] == -1) {
		fp2 << "No path." << endl;
	}
	else {
		fp2 << memo[n - 1][m - 1] << endl;
			while (!direction.empty()) {
				fp2 << "(" << direction.back().first << " " << direction.back().second << ")" << endl;
				direction.pop_back();
			}
	}
		

}