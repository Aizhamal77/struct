#include <iostream>
using namespace std;

struct phone{
	int area; 
	int exchange; 
	int number; 
};

int main(){
	phone ph1 = { 212,767,8900 };
	phone ph2; 
	
	cout << "\n������� ������ ����� (������, ���, �����)";
	cout << "\n(��� ��������� �����):";
	cin >> ph2.area >> ph2.exchange >> ph2.number;
	cout << "\n��� �����: " 
		<< '(' << ph1.area << ")"
		<< ph1.exchange << '-' << ph1.number;
	cout << "\n��� �����: "
		<< '(' << ph2.area << ")"
		<< ph2.exchange << '-' << ph2.number << endl;
	return 0;
}
