#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef struct Edge {
	int start, end, weight, number;
	
};
typedef struct Edgecmp {
	bool operator()(Edge& edge1, Edge& edge2) {
		if (edge1.weight == edge2.weight) {
			return edge1.number > edge2.number;
		}
		else
			return edge1.weight > edge2.weight;
	}
};
typedef struct Vertex {
	int index;
	Vertex* parent;
};
ifstream fp1("mst.inp");
ofstream fp2("mst.out");
vector<Edge> W;
vector<Edge> W2[10001];
Vertex vertex[10001];
int n, m;
bool cmp(const Edge& e1, const Edge& e2) {
	if (e1.weight == e2.weight) {
		return e1.number < e2.number;
	}
	else {
		return e1.weight < e2.weight;
	}
	
}
int find(int i) {
	int now = i;
	int parent = vertex[i].parent->index;
	while (now != parent) {
		now = parent;
		parent = vertex[parent].parent->index;
	}
	return now;
}
void kruskal() {
	sort(W.begin(), W.end(), cmp);
	int sum = 0;
	vector<Edge> F;
	for (int i = 0; i < n; i++) {//initial
		vertex[i].index = i;
		vertex[i].parent = &vertex[i];
	}
	int index = 0;
	while (F.size() < n - 1) {
		int e = W[index].weight;
		int i = W[index].start;
		int j = W[index].end;
		int p = find(i);
		int q = find(j);
		if (p != q) {
			vertex[q].parent = &vertex[p];
			F.push_back(W[index]);
			sum += W[index].weight;
		}
		index++;
	}
	fp2 << "Tree edges by Kruskal algorithm: " << sum << endl;
	for (int i = 0; i < F.size(); i++) {
		fp2 << F[i].number << endl;
	}
}

void Prim(int start) {
	vector<Edge> F;
	int sum = 0,vnear;
	bool nearest[10001] = { false, };
	nearest[start] = true;
	priority_queue<Edge,vector<Edge>,Edgecmp> pq;
	for (int i = 0; i < W2[start].size(); i++) {
		Edge edge = { start,W2[start][i].end,W2[start][i].weight,W2[start][i].number };
		pq.push(edge);
	}
	while (F.size() < n - 1) {
		Edge e;
		while (!pq.empty()) {
			e = pq.top();
			pq.pop();
			if (!nearest[e.end])
				break;
		}
		nearest[e.end] = true;
		F.push_back(e);
		sum += e.weight;
		vnear = e.end;
		for (int i = 0; i < W2[vnear].size(); i++) {
			Edge edge = { vnear, W2[vnear][i].end, W2[vnear][i].weight , W2[vnear][i].number };
			pq.push(edge);
		}
	}
	fp2 << "Tree edges by Prim algorithm with starting vertex " << start << ": " << sum << endl;
	for (int i = 0; i < F.size(); i++) {
		fp2 << F[i].number << endl;
	}
}
int main() {

	
	fp1 >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, tmp;
		fp1 >> start >> end >> tmp;
		W.push_back({ start,end,tmp,i });
		W2[start].push_back({ start,end,tmp,i });
		W2[end].push_back({ end,start,tmp,i });
	}
	
	kruskal();
	Prim(0);
	Prim(n / 2);
	Prim(n - 1);
}