#include <iostream>
using namespace std;

struct phone{
	int area; 
	int exchange; 
	int number; 
};

int main(){
	setlocale(LC_ALL, "Rus");
	phone ph1 = { 212,767,8900 };
	phone ph2; 
	
	cout << "\nВведите полный номер (регион, АТС, номер)";
	cout << "\n(без начальных нулей):";
	cin >> ph2.area >> ph2.exchange >> ph2.number;
	cout << "\nМой номер: " 
		<< '(' << ph1.area << ")"
		<< ph1.exchange << '-' << ph1.number;
	cout << "\nВаш номер: "
		<< '(' << ph2.area << ")"
		<< ph2.exchange << '-' << ph2.number << endl;
	return 0;
}
