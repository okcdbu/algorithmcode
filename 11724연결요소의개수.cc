#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
#pragma warning (disable:4996)
using namespace std;


class Node {
public :
	int number;
	Node* parent;
};
int N, M, cnt = 0;
Node arr[1001];
bool isvisit[1001];
void init(int num) {
	arr[num].number = num;
	arr[num].parent = &arr[num];
	cnt++;
}
int find(int num) {
	int current = num;
	while (true) {
		Node *next = arr[current].parent;
		if (next->number == current)return current;
		current = next->number;
	}
}
void merge(int a,int b) {
	arr[a].parent = &arr[b];
	cnt--;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Text.txt", "rt", stdin);
	cin >> N >> M;
	int tmp,tmp2;
	for (int i = 1; i <= N; i++) {
		init(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp >> tmp2;
		int a = find(tmp);
		int b = find(tmp2);
		if (a != b) {
			merge(a, b);
		}
	}
	cout << cnt;

}