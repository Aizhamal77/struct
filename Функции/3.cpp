#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "Rus");

	void zeroSmaller(int&, int&);
	int a = 4, b = 7, c = 11, d = 9;
	zeroSmaller(a, b);
	
		zeroSmaller(c, d);
	cout << "\na=" << a << " b=" << b
		<< " c=" << c << " d=" << d;
	return 0;
}

void zeroSmaller(int& first, int& second) {
	if (first < second)
		first = 0;
	else
		second = 0;
}
