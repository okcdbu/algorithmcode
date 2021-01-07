#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstring>
#define REST 100000
using namespace std;
ifstream fp1("sum.inp");
ofstream fp2("sum.out");
int DP[201][200001];
vector<int> arr;
int W;
int sos(int n)
{
	for (int i = 0; i <= n; i++)
		DP[i][0] = 1;

	for (int i = 1; i <= W; i++)
		DP[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if(j < arr[i - 1])
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] + DP[i - 1][j - arr[i - 1]];

			DP[i][j] %= REST;
		}
	}
	return DP[n][W];
}

int main() {
	int T;
	fp1 >> T;
	while (T--) {
		int n;
		fp1 >> n >> W;
		for (int i = 0; i < n; i++) {
			int buf;
			fp1 >> buf;
			arr.push_back(buf);
		}
		sort(arr.begin(),arr.end());
		int answer = sos(n);
		fp2 << answer << endl;
		answer = 0;
		arr.clear();
		memset(DP, 0, sizeof(DP));
	}
}