#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fp1("rectangles.inp");
ofstream fp2("rectangles.out");
typedef struct abc {
	int a, b, c;
};
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
bool cmp(const abc& a, const abc& b) {
	return a.c < b.c;
}
int main() {
	int T;
	fp1 >> T;
	while (T--) {
		int L;
		vector<abc> pythagorean;
		fp1 >> L;
		for (int y = 1; y < 501; y++) {
			for (int x = y + 1; x < 501; x++) {
				int a, b, c;
				a = 2 * x * y;
				b = x * x - y * y;
				c = x * x + y * y;
				if (a > b)
					swap(a, b);
				if (gcd(a, b) == 1) {
					abc tmp = { a,b,a + b };
					pythagorean.push_back(tmp);
				}
			}
		}
		sort(pythagorean.begin(), pythagorean.end(), cmp);
		int Lmax = 0,cnt  = 0;
		for (vector<abc>::iterator iter = pythagorean.begin(); iter != pythagorean.end(); iter++) {
			Lmax += iter->c * 2;
			if (Lmax > L)
				break;
			cnt++;
		}
		fp2 << cnt << endl;
	}
}