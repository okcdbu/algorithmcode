#include <iostream>
using namespace std;
#define max 1000000
bool isprime[max + 1];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= max; ++i)
	{
		if (!isprime[i])
		{
			for (int j = i + i; j <= max; j += i)
			{
				if (!isprime[j])
				{
					isprime[j] = true;
				}
			}
		}
	}
	int n;
	for (int T = 0; T <= max / 10; T++) {
		
		cin >> n;
		if (n == 0)
			break;
		for (int i = 3; i <= n; i += 2) {
			if (!isprime[i] && !isprime[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
	}
}