#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string flipfront(string S) {
	string flip = "******";
	flip[0] = S[4];
	flip[4] = S[5];
	flip[5] = S[1];
	flip[1] = S[0];
	flip[2] = S[2];
	flip[3] = S[3];
	return flip;
}
string flipleft(string S) {
	string flip = "******";
	flip[0] = S[2];
	flip[2] = S[5];
	flip[5] = S[3];
	flip[3] = S[0];
	flip[1] = S[1];
	flip[4] = S[4];
	return flip;
}
string fliprotate(string S) {
	string flip = "******";
	flip[2] = S[1];
	flip[4] = S[2];
	flip[3] = S[4];
	flip[1] = S[3];
	flip[0] = S[0];
	flip[5] = S[5];
	return flip;
}
bool isEqual(string A, string B) {
	for (int i = 0; i < A.length(); i++) {
		if (A[i] != B[i])
			return false;
	}
	return true;
}
int main() {
	ifstream fp1("cube.inp");
	ofstream fp2("cube.out");

	while (true) {
		string A, B, buf;
		fp1 >> buf;
		A = buf.substr(0, 6);
		B = buf.substr(6);
		bool answer = false;
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					B = flipleft(B);
					if (isEqual(A, B)) {
						answer = true;
						break;
					}
				}
				B = flipfront(B);
			}
			B = fliprotate(B);
		}
		if (answer) {
			fp2 << "TRUE" << endl;
		}
		else {
			fp2 << "FALSE" << endl;
		}
		bool isescape = true;
		for (int l = 1; l < buf.length(); l++) {
			char a = buf[0];
			if (a != buf[l]) {
				isescape = false;
				break;
			}
		}
		if (isescape)
			break;
	}
}