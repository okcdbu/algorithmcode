#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
ifstream fp1("freelancer.inp");
ofstream fp2("freelancer.out");
typedef struct Job {
	int time;
	int income;
	int index;
	double cost;
};
vector<bool> isvisit,ans;
vector<Job> arr;
Job answer = { 999999999,0 };
int n, I;
bool cmp(const Job& a, const Job& b) {
	return a.cost > b.cost;
}
void maxCost(int idx, int nsum, int time) {
	if (nsum > I && answer.time <= time) {
		return;
	}
	if (nsum >= I && answer.time >= time) {//최적일때
		answer.time = time;
		answer.income = nsum;
		ans.assign(isvisit.begin(), isvisit.begin() + 10);
		return;
	}
	if (idx < n) {
		int timesum = 0, timelimit = I - nsum;
		double limitsum = 0;
		for (int i = idx; i < n; i++) {
			if (limitsum + arr[i].income < timelimit) {
				timesum += arr[i].time;
				limitsum += arr[i].income;
			}
			else {
				limitsum = timelimit - limitsum;
				timesum += arr[i].time * limitsum / arr[i].income;
				break;
			}
		}
		if (answer.time >= timesum + time) {//백트래킹
			isvisit[arr[idx].index] = true;
			maxCost(idx + 1, nsum + arr[idx].income, time + arr[idx].time);
			isvisit[arr[idx].index] = false;
			maxCost(idx + 1, nsum, time);
		}
	}

}
int main() {

	fp1 >> n >> I;
	for (int i = 0; i < n; i++) {
		int tmpt, tmpi;
		fp1 >> tmpi >> tmpt;
		arr.push_back({ tmpt,tmpi,i,(double)tmpi / (double)tmpt });
	}
	sort(arr.begin(), arr.end(), cmp);
	isvisit.assign(arr.size(), false);
	maxCost(0, 0, 0);
	fp2 << answer.time << " " << answer.income << endl;
	for (int i = 0; i < 10; i++) {
		if (ans[i]) {
			fp2 << 1 << " ";
		}
		else {
			fp2 << 0 << " ";
		}
	}
	arr.clear();
}