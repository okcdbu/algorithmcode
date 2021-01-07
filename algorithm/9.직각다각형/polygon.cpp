#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int abs(int n) {
	if (n < 0)
		n = -n;
	return n;
}
vector<int> getparr(vector<int> p) { 
	int m = p.size();
	int j = 0;
	vector<int> pi(m, 0); 
	for (int i = 1; i < m; i++) { 
		while (j > 0 && p[i] != p[j]) 
			j = pi[j - 1]; 
		if (p[i] == p[j]) 
			pi[i] = ++j; 
	} 
	return pi; 
} 
vector<int> kmp(vector<int> s, vector<int> p) {
	vector<int> ans; 
	auto pi = getparr(p); 
	int n = s.size(), m = p.size(), j = 0; 
	for (int i = 0; i < n; i++) { 
		while (j > 0 && s[i] != p[j]) 
			j = pi[j - 1]; 
		if (s[i] == p[j]) { 
			if (j == m - 1) { 
				ans.push_back(i - m + 1); 
				j = pi[j]; 
			} 
			else { 
				j++; 
			} 
		} 
	} 
	return ans; 
}

int main() {
	ifstream fp1("polygon.inp");
	ofstream fp2("polygon.out");

	int T;
	fp1 >> T;
	while (T--) {
		int n;
		vector<int> A, B;
		fp1 >> n;
		for (int i = 0; i < n; i++) {
			int buf;
			fp1 >> buf;
			A.push_back(buf);
		}
		for (int i = 0; i < n; i++) {
			int buf;
			fp1 >> buf;
			B.push_back(buf);
		}
		A.insert(A.end(), A.begin(), A.end());
		vector<int> ans = kmp(A, B);
		reverse(A.begin(), A.end());
		A.push_back(A[0]);
		for (int i = 0; i < A.size() - 1; i++) {
			if (A[i + 1] > 0) {
				A[i] = -abs(A[i]);
			}
			else {
				A[i] = abs(A[i]);
			}
		}
		A.pop_back();
		vector<int> revans = kmp(A, B);
		if (!ans.empty() || !revans.empty())
			fp2 << 1 << endl;
		else
			fp2 << 0 << endl;
	}
}