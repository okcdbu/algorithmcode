#include <iostream>
#include <fstream>
#include <string>
#pragma warning (disable:4996)
using namespace std;
bool bitmap[200][200];
int col, row;
int bitmax;
int cnt;
int length;
string inbuffer;
int mergeiter = 0;
ifstream fp1;
ofstream fp2;
void decomposition(int stcol,int strow,int colsize,int rowsize) {
	if (rowsize <= 0 || colsize <= 0)
		return;
	bool isD = false;
	bool startbit = bitmap[stcol][strow];
	for (int i = stcol; i < stcol + colsize; i++) {
		for (int j = strow; j < strow + rowsize; j++) {
			if (startbit != bitmap[i][j]) {
				isD = true;
				break;
			}
		}
		if (isD)
			break;
	}
	if (isD) {
		if (length >= 50) {
			fp2 << endl;
			length = 0;
		}
		fp2 << "D";
		length++;
		int coltop, colbottom, rowleft, rowright;
		colbottom = colsize / 2;
		coltop = colsize - colbottom;
		rowright = rowsize / 2;
		rowleft = rowsize - rowright;
		decomposition(stcol, strow, coltop, rowleft);
		decomposition(stcol, strow + rowleft, coltop, rowright);
		decomposition(stcol + coltop, strow, colbottom, rowleft);
		decomposition(stcol + coltop, strow + rowleft, colbottom, rowright);
	}
	else {
		if (startbit) {
			if (length >= 50) {
				fp2 << endl;
				length = 0;
			}

			fp2 << "1";
			length++;
			return;
		}
		else {
			if (length >= 50) {
				fp2 << endl;
				length = 0;
			}
			fp2 << "0";
			length++;
			return;
		}
	}
}
void merger(int stcol,int strow,int colsize,int rowsize) {
	if (rowsize <= 0 || colsize <= 0)
		return;
	char buffer;
	buffer = inbuffer[mergeiter];
	mergeiter++;
	if (buffer == 'D') {
		int coltop, colbottom, rowleft, rowright;
		colbottom = colsize / 2;
		coltop = colsize - colbottom;
		rowright = rowsize / 2;
		rowleft = rowsize - rowright;
		merger(stcol, strow, coltop, rowleft);
		merger(stcol, strow + rowleft, coltop, rowright);
		merger(stcol + coltop, strow, colbottom, rowleft);
		merger(stcol + coltop, strow + rowleft, colbottom, rowright);
	}
	else if (buffer == '1') {
		for (int i = stcol; i < stcol + colsize; i++) {
			for (int j = strow; j < strow + rowsize; j++) {
				bitmap[i][j] = true;
			}
		}
	}
	else if (buffer == '0') {
		for (int i = stcol; i < stcol + colsize; i++) {
			for (int j = strow; j < strow + rowsize; j++) {
				bitmap[i][j] = false;
			}
		}
	}
	

}
int main() {
	fp1.open("bitmap.inp");
	fp2.open("bitmap.out");
	char buffer,lastbuf = 0;
	fp1 >> buffer;
	while (true) {
		
		if (buffer == '#')
			break;
		if (lastbuf == 'B' && buffer == 'B') {
			fp1 >> buffer;
			continue;
		}
			
		fp1 >> col >> row;
		fp1.ignore();
		bitmax = col * row;
		cnt = 0;
		if (buffer == 'B') {
			char buf;
			while (cnt < bitmax) {
				fp1 >> buf;
				if (buf == '/n')
					continue;
				inbuffer += buf;
				cnt++;
			}
			
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
					if (inbuffer[i*row + j] == '1') {
						bitmap[i][j] = true;
					}
				}
			}
			fp2 << "D " << col << " " << row << endl;
			decomposition(0, 0, col, row);
			fp2 << "\n";
			lastbuf = 'B';
		}
		else { // buffer == 'D'
			fp2 << "B " << col << " " << row << endl;
			char buf;
			while (true) {
				fp1 >> buf;
				if (buf == '\n')
					continue;
				else if (buf == 'B' || buf == '#') {
					buffer = buf;
					break;
				}
				inbuffer += buf;
			}
			merger(0, 0, col, row);
			int k = 0;
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
					if (k >= 50) {
						k = 0;
						fp2 << endl;
					}
					fp2 << bitmap[i][j] ? 1 : 0;
					k++;
				}
			}
			fp2 << endl;
			lastbuf = 'D';
		}
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				bitmap[i][j] = false;
			}
		}
		cnt = 0;
		length = 0;
		inbuffer = "";
		mergeiter = 0;
	}
}