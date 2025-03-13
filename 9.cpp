#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};


void swap(Time& t1, Time& t2) {
    
    Time temp = t1;
    t1 = t2;
    t2 = temp;
}

int main() {
    setlocale(LC_ALL, "Rus");

    Time t1, t2;

    cout << "������� ����, ������ � ������� ��� ������� ������� (t1): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "������� ����, ������ � ������� ��� ������� ������� (t2): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    cout << "\n�� ������:" << endl;
    cout << "t1: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << endl;
    cout << "t2: " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;

    swap(t1, t2);

    cout << "\n����� ������:" << endl;
    cout << "t1: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << endl;
    cout << "t2: " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;

    return 0;
}
