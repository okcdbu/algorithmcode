#include <iostream>
#include <fstream>
using namespace std;
ifstream fp1;
ofstream fp2;
int T;
long long M;
class Matrix {
public:
	long long data[2][2];
	Matrix() {
		data[0][0] = 1; 
		data[0][1] = 1; 
		data[1][0] = 1; 
		data[1][1] = 0;
	}
	Matrix multiply(Matrix A, Matrix B);
};
Matrix Matrix::multiply(Matrix A, Matrix B) {
	Matrix C = Matrix();
	C.data[0][0] = (((A.data[0][0] % M) * (B.data[0][0] % M)) % M + ((A.data[0][1] % M) * (B.data[1][0] % M)) % M) % M;
	C.data[0][1] = (((A.data[0][0] % M) * (B.data[1][0] % M)) % M + ((A.data[0][1] % M) * (B.data[1][1] % M)) % M) % M;
	C.data[1][0] = (((A.data[1][0] % M) * (B.data[0][0] % M)) % M + ((A.data[1][1] % M) * (B.data[1][0] % M)) % M) % M;
	C.data[1][1] = (((A.data[1][0] % M) * (B.data[1][0] % M)) % M + ((A.data[1][1] % M) * (B.data[1][1] % M)) % M) % M;
	return C;
}
Matrix division(Matrix mat, long long n) {
	if (n > 1) {
		mat = division(mat, n / 2);
		mat = mat.multiply(mat, mat);
		if (n % 2 != 0) {
			Matrix mat2 = Matrix();
			mat = mat.multiply(mat, mat2);
		}
	}
	return mat;
}
long long fibonacci(long long n) {
	if (n == 0)
		return 0;
	Matrix mat = Matrix();
	mat = division(mat, n);
	return mat.data[1][0] % M;
}
int main() {
	fp1.open("fibonacci.inp");
	fp2.open("fibonacci.out");
	long long a, b, c, d;
	
	fp1 >> T;
	for (int i = 0; i < T; i++) {
		fp1 >> a >> b >> c >> d >> M;
		long long fa, fb, fc, fd;
		fa = fibonacci(a);
		fb = fibonacci(b);
		fc = fibonacci(c);
		fd = fibonacci(d);
		
		fp2 << ((fa * fb) % M + (fc * fd) % M) % M << endl;
	}
}