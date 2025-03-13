#include <iostream>
using namespace std;

struct Distance {
	int feet;
	float inches;
};

Distance bigengl(Distance, Distance);
void engldisp(Distance);

int main(){
	setlocale(LC_ALL, "Rus");

	Distance d1, d2, d3; 
	
		cout << "\nÂâåäèòå ÷èñëî ôóòîâ:"; cin >> d1.feet;
	cout << "Ââåäèòå ÷èñëî äþéìîâ:"; cin >> d1.inches;

	
		cout << "\nÂâåäèòå ÷èñëî ôóòîâ:"; cin >> d2.feet;
	cout << "Ââåäèòå ÷èñëî äþéìîâ:"; cin >> d2.inches;
	d3 = bigengl(d1, d2); 

	cout << "\nd1="; engldisp(d1);
	cout << "\nd2="; engldisp(d2);
	cout << "\níàèáîëüøåå — "; engldisp(d3); cout << endl;
	return 0;
}

Distance bigengl(Distance dd1, Distance dd2){

	if (dd1.feet > dd2.feet) 
		return dd1;
	if (dd1.feet < dd2.feet)
		return dd2;
	if (dd1.inches > dd2.inches)
		
		return dd1; 
	else 
		return dd2;
}

void engldisp(Distance dd){

	cout << dd.feet << "\'-" << dd.inches << "\"";
}
