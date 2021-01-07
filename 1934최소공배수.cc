#include <iostream>
#include <fstream>
using namespace std;
int gcd(int a, int b) {
	int temp;
	while (b > 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		cout << A * B / gcd(A, B) << endl;
	}
	
}