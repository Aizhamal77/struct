#include <iostream>
using namespace std;

class Date {
private:
    int month;  
    int day;    
    int year;  

public:
   
    Date() : month(0), day(0), year(0) {}

   
    void getDate() {
        char slash;  
        cout << "������� ���� � ������� MM/DD/YY: ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {
        cout << "����: " << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Date date1;  
    date1.getDate();
    date1.showDate();

    return 0;
}
