#include <iostream>
using namespace std;

double power(double n, int p = 2);

int main(){
	setlocale(LC_ALL, "Rus");

	double number, answer;
	int pow;
	char yeserno;
	cout << "\n¬ведите число:";
	cin >> number;
	cout << "Ѕудете вводить степень (y/n)?";
	cin >> yeserno;
	if (yeserno == 'y'){

		cout << "¬ведите степень:";
		cin >> pow;
		answer = power(number, pow);
	}
	else
		answer = power(number);
	cout << "ќтвет " << answer << endl;
	return 0;
}



double power(double n, int p){

	double result = 1.0;
	for (int j = 0; j < p; j++)
		result *= n;
	return result;
}