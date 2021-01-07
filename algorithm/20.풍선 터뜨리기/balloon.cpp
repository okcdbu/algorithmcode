#include <iostream>
#include <fstream>

using namespace std;
int DP[3][1001];
int totalcnt[1001];
int main() {
	ifstream fp1("balloon.inp");
	ofstream fp2("balloon.out");
	while (true) {
		int n;
		fp1 >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			fp1 >> DP[0][i];
		}
		int liscount[1001] = { 0, };
		int lismax = -1;
		for (int i = n - 1; i >= 0; i--) {
			int max = -1, buf = 0;

			for (int j = i + 1; j < n; j++) {
				if (DP[0][j] >= DP[0][i]) {
					if (DP[1][j] > max) {
						max = DP[1][j];
						buf = 0;
					}
					if (DP[1][j] == max) {
						buf += DP[2][j];
					}
				}
			}
			DP[2][i] = buf;

			if (max == -1) {
				DP[1][i] = 1;
				DP[2][i] = 1;
			}
			else DP[1][i] = max + 1;
		}
		for (int i = 0; i < n; i++) {
			liscount[DP[1][i]] += DP[2][i];
			if (DP[1][i] > lismax) lismax = DP[1][i];
		}
		fp2 << lismax << " " << liscount[lismax] << endl;



	}
	
}