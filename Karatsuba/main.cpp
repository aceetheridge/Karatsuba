#include <iostream>
#include <cmath>
using namespace std;
int digits(int x){
		int leaf = (int)log10(x) + 1;
		return leaf;
}
int powmod(int x) {
	int leaf = (int)pow(10, x);
	return leaf;
}
int karatsuba(int x, int y) {
	int p1, p2, p3, p4, n, tree, f1, f2, f3;
	if (x == 0 || y == 0) {
		return 0;
	}
	int xn = digits(x);
	int yn = digits(y);
	n =  digits((int)fmin(x, y));
	int m = (n / 2) + (n % 2);// odd check
	if ( xn == 1 && yn == 1) {
		return x * y;
	}
	else {
		p1 = x / (pow(10, m));
		p2 = x % powmod(m);
		p3 = y / (pow(10, m));
		p4 = y % powmod(m);
		f1 = karatsuba(p1, p3);
		f3 = karatsuba(p2, p4);
		f2 = karatsuba(p1 + p2, p3 + p4) - f1 - f3;
		tree = f1*(int)pow(10, (2 * m)) + f2*(int)pow(10, m) + f3;
	}
	return tree;
}
int main() {
	cout << "7*6 = " << karatsuba(7, 6) << " "  << 42 << endl; // 42
	cout << "15*15 = " << karatsuba(15, 15) << " " << 225 << endl; // 225
	cout << "6*13 = " << karatsuba(6, 13) << " " << 78 << endl; // 78
	cout << "51*49 = " << karatsuba(51, 49) << " " << 2499 << endl; // 2499
	cout << "111*111 = " << karatsuba(111, 111) << " " << 12321 << endl; // 12321
	cout << "5678*1234 = " << karatsuba(5678, 1234) << " " << 7006652 << endl; // 7006652
	cout << "12345678*1 = " << karatsuba(12345678, 1) << " " << 12345678 << endl; // 12345678
	cout << "12345678*0 = " << karatsuba(12345678, 0) << " " << 0 << endl; // 0
	system("PAUSE");
	return 0;
}