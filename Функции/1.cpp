#include <iostream>
using namespace std;

float circarea(float radius);

int main(){
	setlocale(LC_ALL, "Rus");

	double rad;
	cout << "\nÂâĺäčňĺ đŕäčóń îęđóćíîńňč:";
	
		cin >> rad;
	cout << "Ďëîůŕäü đŕâíŕ " << circarea(rad) << endl;
	return 0;
}

float circarea(float r)
{
	const float PI = 3.14159F;
	return r * r * PI;
}
