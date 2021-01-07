#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int dp[1001][1001];
int DPMinsize(string s, int size){
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			dp[i][j] = 0;
		}
	}
	int k, start, end;
	for (k = 1; k < size; k++){
		for (start = 0,end = k; end < size; start++, end++){
			dp[start][end] = (s[start] == s[end]) ? dp[start + 1][end - 1] : (min(dp[start][end - 1], dp[start + 1][end]) + 1);
		}
	}
	return dp[0][size-1];

}
int main() {
	ifstream fp1("palindrome.inp");
	ofstream fp2("palindrome.out");

	int T;
	fp1 >> T;
	for (int i = 0; i < T; i++) {
		string S;
		fp1 >> S;
		int len = S.length();
		int answer = DPMinsize(S, len);
		if (answer > 2) answer = -1;
		fp2 << answer << endl;
	}
}