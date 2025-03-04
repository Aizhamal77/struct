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
	
	cout << "\nÂâåäèòå ïîëíûé íîìåð (ðåãèîí, ÀÒÑ, íîìåð)";
	cout << "\n(áåç íà÷àëüíûõ íóëåé):";
	cin >> ph2.area >> ph2.exchange >> ph2.number;
	cout << "\nÌîé íîìåð: " 
		<< '(' << ph1.area << ")"
		<< ph1.exchange << '-' << ph1.number;
	cout << "\nÂàø íîìåð: "
		<< '(' << ph2.area << ")"
		<< ph2.exchange << '-' << ph2.number << endl;
	return 0;
}
