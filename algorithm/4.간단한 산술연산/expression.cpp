#include <stdio.h>
#pragma warning (disable:4996)
#include <stack>
using namespace std;
stack<char> op;
stack<int> num;
int T;
bool calculate();
int main() {
	FILE *fp1 = fopen("expression.inp", "rt");
	FILE* fp2 = fopen("expression.out", "wt");
	
	fscanf(fp1, "%d ", &T);
	for (int i = 0; i < T; i++) {
		char buffer;
		bool isError = false;
		while (true) {
			fscanf(fp1, "%c", &buffer);
			if (buffer == '=') {
				while (!op.empty()) {
					if (!calculate()) {
						isError = true;
						break;
					}
				}
				break;
			}
			else if (buffer == '*' || buffer == '/' || buffer == '%' ) {
				while (!op.empty() && (op.top() != '+' && op.top() != '-')) {
					if (!calculate()) {
						isError = true;
						break;
					}
				}
				op.push(buffer);
			}
			else if(buffer == '+' || buffer == '-'){
				while (!op.empty())
					if (!calculate()) {
						isError = true;
						break;
					}
				op.push(buffer);
			}
			else if(buffer >='0' && buffer<='9'){
				int j = 0;
				char numb[10];
				for (int m = 0; m < 10; m++)
					numb[m] = 0;
				int number;
				numb[j] = buffer;
				while (true) {
					j++;
					fscanf(fp1, "%c", &buffer);
					if (buffer == ' ')
						break;
					numb[j] = buffer;
				}
				sscanf(numb, "%d", &number);
				num.push(number);
			}
			if (isError) {
				while (true) {
					fscanf(fp1, "%c", &buffer);
					if (buffer == '=')
						break;
				}
				break;
			}
				
		}
		if (isError) {
			fprintf(fp2, "Error!\n");
		}
		else {
			fprintf(fp2, "%d\n", num.top());
		}
		while (!op.empty())
			op.pop();
		while (!num.empty())
			num.pop();
	}
}
bool calculate() {
	int b = num.top();
	num.pop();
	int a = num.top();
	num.pop();
	char oper = op.top();
	op.pop();
	int result;
	switch (oper) {
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0)
				return false;
			result = a / b;
			break;
		case '%':
			if (b == 0)
				return false;
			result = a % b;
			break;
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		default:
			result = 0;
	}
	num.push(result);
	return true;
}