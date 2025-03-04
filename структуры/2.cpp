#include <iostream>
using namespace std;

struct point{
	int xCo; 
	int yCo; 
};

int main(){
	setlocale(LC_ALL, "Rus");
	point p1, p2, p3; 
	cout << "\nÂâåäèòå êîîðäèíàòû p1:";
	cin >> p1.xCo >> p1.yCo; 
	cout << "Ââåäèòå êîîðäèíàòû p2:";
	cin >> p2.xCo >> p2.yCo;
	p3.xCo = p1.xCo + p2.xCo; 
	p3.yCo = p1.yCo + p2.yCo; 
	cout << "Êîîðäèíàòû p1+p2:" 
		<< p3.xCo << "," << p3.yCo << endl;
	return 0;
}
