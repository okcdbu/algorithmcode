#include <stdio.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
#define FRAME 10
/*
	볼링 계산 방법 구형(2018년 개정 전)
	1824043 강등원
*/
int T;
FILE* fp1;
FILE* fp2;
typedef struct fragment {
	int score;
	int index;
	
	fragment(int score1, int index1) {
		score = score1;
		index = index1;
	}
	fragment* next;
};

typedef struct Scorearr {
	fragment *first;
	int score;
};

int main() {
	
	fp1 = fopen("bowling.inp", "rt");
	fp2 = fopen("bowling.out", "wt");
	fscanf(fp1, "%d ", &T);
	for (int count = 0; count < T; count++) {
		vector<fragment> arr;
		int score = 0,fragcnt = 0;
		int state[10] = { 0, };//0 is open, 1 is strike, 2 is spare
		Scorearr scorearr[10] = { 0, };
		for (int i = 0; i < FRAME; i++) {
			int first, second, third ;
			fscanf(fp1, " %d", &first);
			if (first == 10) {
				fragment *tmp = new fragment(10, i);
				state[i] = 1;
				if (!arr.empty()) {
					arr.back().next = tmp;
				}
				arr.push_back(*tmp);
				fragcnt++;
			}
			else {
				fscanf(fp1, "%d ", &second);
				fragment *tmp1 = new fragment(first, i);
				fragment *tmp2 = new fragment(second, i);
				tmp1->next = tmp2;
				if (!arr.empty()) {
					arr.back().next = tmp1;
				}
				arr.push_back(*tmp1);
				arr.push_back(*tmp2);
				fragcnt++; fragcnt++;
				if (first + second == 10) {
					state[i] = 2;
				}
			}
			if (i == 9) {
				if (first == 10) {
					fscanf(fp1, " %d", &second);
					fscanf(fp1, " %d", &third);
					fragment *tmp1 = new fragment(second, i), *tmp2 = new fragment(third, i);
					fragcnt++; fragcnt++;
					tmp1->next = tmp2;
					if (!arr.empty()) {
						arr.back().next = tmp1;
					}
					arr.push_back(*tmp1);
					arr.push_back(*tmp2);
				}
				else if(first + second == 10){
					fscanf(fp1, " %d", &third);
					fragment *tmp1 = new fragment(third, i);
					fragcnt++;
					
					if (!arr.empty()) {
						arr.back().next = tmp1;
					}
					arr.push_back(*tmp1);
				}
			}
		}
		int lastindex = -1;
		for (int k = 0,index = 0; k < fragcnt; k++) {
			index = arr[k].index;
			score += arr[k].score;
			scorearr[index].score += arr[k].score;
			if (lastindex != index) {
				scorearr[index].first = &arr[k];
			}
			
			lastindex = index;
		}
		for (int k = 0; k< FRAME -1; k++) {
			if (state[k] == 1) {
				score += (scorearr[k + 1].first)->score + (scorearr[k + 1].first)->next->score;
			}
			else if (state[k] == 2) {
				score += (scorearr[k + 1].first)->score;
			}
		}
		fprintf(fp2, "%d\n", score);
	}

}