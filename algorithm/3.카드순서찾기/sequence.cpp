#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996)
int Sarr[1000];
int Carr[1000];
bool Varr[1000];
int answer[1000];
int main() {
	FILE* fp1 = fopen("sequence.inp", "rt");
	FILE* fp2 = fopen("sequence.out", "wt");
	int n;
	fscanf(fp1, "%d ", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fp1, "%d ", &Sarr[i]);
	}
	for (int i = 0; i < n; i++) {
		fscanf(fp1, "%d ", &Carr[i]);
	}
	std::sort(Sarr, Sarr + n);
	for (int i = n - 1; i >= 0; i--) {
		int Vcnt = 0;
		int Ccnt = Carr[i];
		int Scnt = -1;
		for (int j = 0; j < n; j++) {
			if (!Varr[j])Scnt++;
			if (Scnt == Ccnt) {
				Varr[j] = true;
				answer[i] = Sarr[j];
				break;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		fprintf(fp2, "%d\n", answer[j]);
	}
}