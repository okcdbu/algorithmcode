#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	FILE* fp1 = fopen("primefactor.inp", "rt");
	FILE* fp2 = fopen("primefactor.out", "wt");

	bool isprime[100001] = { false, };//합성수는 true 소수는 false
	for (int i = 2; i*i <= 100000; i++) {
		for (int j = i * i; j <= 100000; j += i) {
			isprime[j] = true;
		}
	}
	int T;
	fscanf(fp1, "%d ", &T);
	for (int k = 0; k < T; k++) {
		int number;
		fscanf(fp1, "%d ", &number);
		if (isprime[number]) {
			int sum = 0;
			for (int i = 2; i <= number; i++)
				while (number % i == 0)
				{
					number /= i;
					sum += i;
				}
			fprintf(fp2, "%d\n", sum);
		}
		else {
			fprintf(fp2, "Prime Number\n");
		}
	}
}