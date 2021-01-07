#include <stdio.h>
#pragma warning (disable:4996)
FILE* fp1;
FILE* fp2;
int unavailarr[99];
int grid[10][10];
int main() {
	fp1 = fopen("path.inp", "rt");
	fp2 = fopen("path.out", "wt");

	int start, end, unavailcnt;
	fscanf(fp1, "%d %d %d", &start, &end, &unavailcnt);
	for (int i = 0; i < unavailcnt; i++) {
		fscanf(fp1, "%d ", &unavailarr[i]);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = -1;
		}
	}
	int startsplitten = start / 10;
	int startsplitone = start % 10;
	int endsplitten = end / 10;
	int endsplitone = end % 10;
	if (startsplitten < endsplitten) {
		int tmp = start;
		start = end;
		end = tmp;
	}
	startsplitten = start / 10;
	startsplitone = start % 10;
	endsplitten = end / 10;
	endsplitone = end % 10;
	int garo;
	if (startsplitone > endsplitone) {//좌상향
		garo = endsplitone - startsplitone;
		int sero = endsplitten - startsplitten;
		for (int k = 0; k < unavailcnt; k++) {//막힌지점 0으로 고정
			grid[unavailarr[k] / 10][unavailarr[k] % 10] = 0;
		}
		grid[startsplitten][startsplitone] = 1;
		for (int c = startsplitten - 1; c >= endsplitten; c--) {//시작점 윗줄 1로 고정
			if (grid[c][startsplitone] != 0) {
				grid[c][startsplitone] = grid[c + 1][startsplitone];
			}
		}
		for (int r = startsplitone - 1; r >= endsplitone; r--) {//시작점 왼쪽 1로 고정
			if (grid[startsplitten][r] != 0) {
				grid[startsplitten][r] = grid[startsplitten][r + 1];
			}
			
		}

		bool isblock = true;
		for (int i = startsplitten - 1; i >= endsplitten; i--) {
			for (int j = startsplitone - 1; j >= endsplitone; j--) {
				if (grid[i][j] == -1) {
					grid[i][j] = grid[i + 1][j] + grid[i][j + 1];//아래와 왼쪽의 값을 더함
				}
			}
			
		}
		fprintf(fp2, "%d", grid[endsplitten][endsplitone]);
	}
	else if (startsplitone < endsplitone) {//우상향
		garo = startsplitone - endsplitone;
		int sero = endsplitten - startsplitten;
		grid[startsplitten][startsplitone] = 1;
		for (int k = 0; k < unavailcnt; k++) {//막힌지점 0으로 고정
			grid[unavailarr[k] / 10][unavailarr[k] % 10] = 0;
		}
		for (int c = startsplitten - 1; c >= endsplitten; c--) {//시작점 윗줄 1로 고정
			if (grid[c][startsplitone] != 0) {
				grid[c][startsplitone] = grid[c + 1][startsplitone];
			}
		}
		for (int r = startsplitone + 1; r <= endsplitone; r++) {//시작점 오른쪽 1로 고정
			if (grid[startsplitten][r] != 0) {
				grid[startsplitten][r] = grid[startsplitten][r - 1];
			}
		}
		for (int i = startsplitten - 1; i >= endsplitten; i--) {

			for (int j = startsplitone + 1; j <= endsplitone; j++) {
				if (grid[i][j] == -1) {
					
					grid[i][j] = grid[i + 1][j] + grid[i][j - 1];//아래와 왼쪽의 값을 더함
				}
			}
			
		}
		fprintf(fp2, "%d", grid[endsplitten][endsplitone]);
	}
	else {//정상향
		garo = 0;
		for (int c = startsplitten; c >= endsplitten; c--) {//시작점 윗줄 1로 고정
			grid[c][startsplitone] = 1;
		}
		for (int k = 0; k < unavailcnt; k++) {//막힌지점 0으로 고정
			grid[unavailarr[k] / 10][unavailarr[k] % 10] = 0;
		}
		bool isblock = false;
		for (int i = startsplitten; i >= endsplitten; i--) {//윗줄 올라가며 막혀있는지확인
			if (grid[i][startsplitone] == 0) {
				isblock = true;
				break;
			}
				
		}
		fprintf(fp2, "%d", isblock ? 0 : 1);//막히면 0, 아니면 1
	}

}