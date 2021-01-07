#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int WLH[201][201][201];
int main() {
	ifstream fp1("cube.inp");
	ofstream fp2("cube.out");
	int T;
	for (int i = 1; i < 201; i++) {
		for (int j = 1; j < 201; j++) {
			for (int k = 1; k < 201; k++) {
				if (WLH[i][j][k] == 0) {
					if (i == j && j == k) {
						WLH[i][j][k] = 1;
						continue;
					}
					else {
						WLH[i][j][k] = INT_MAX;
						for (int w = 1; w <= i / 2; w++) {
							WLH[i][j][k] = min(WLH[i][j][k], WLH[w][j][k] + WLH[i - w][j][k]);
						}
						for (int l = 1; l <= j / 2; l++) {
							WLH[i][j][k] = min(WLH[i][j][k], WLH[i][l][k] + WLH[i][j - l][k]);
						}
						for (int h = 1; h <= k / 2; h++) {
							WLH[i][j][k] = min(WLH[i][j][k], WLH[i][j][h] + WLH[i][j][k - h]);
						}
						 WLH[j][i][k] = WLH[i][k][j] = WLH[k][j][i] = WLH[j][k][i] = WLH[k][i][j] = WLH[i][j][k];
					}
				}
			}
		}
	}
	int W, L, H;
	fp1 >> T;
	while (T--) {
		fp1 >> W >> L >> H;
		fp2 << WLH[W][L][H] << endl;
	}
}