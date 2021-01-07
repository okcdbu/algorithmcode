#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ifstream fp1("card.inp");
	ofstream fp2("card.out");

	int T;
	fp1 >> T;
	while (T--) {
		int n, arr[1000];
		fp1 >> n;
		for (int i = 0; i < n; i++) {
			fp1 >> arr[i];
		}
		int summax[1000];
		for (int i = 0; i < n; i++) {
			if (i < 3) {
 				summax[i] = arr[i];
			}
			else if(i==3){
				summax[i] = max(summax[i - 2], summax[i - 3]) + arr[i];
			}
			else if (i == 4) {
				summax[i] = max(summax[i - 2], max(summax[i - 3], summax[i - 4])) + arr[i];
			}
			else if (i == 5) {
				summax[i] = max(summax[i-5] + arr[i-2], max(summax[i - 3], summax[i - 4])) + arr[i];
			}
			else {
				summax[i] = max(summax[i - 3], summax[i - 4]);
				summax[i] = max(summax[i], max(summax[i - 5], summax[i - 6]) + arr[i - 2]) + arr[i];
			}
		}
		fp2 << summax[n - 1] << endl;
	}
}