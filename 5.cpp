#include <iostream>
using namespace std;

struct date
{
    int day;  
    int month; 
    int year; 
};


int main()
{
    setlocale(LC_ALL, "Rus");
    date user_date; 

    cout << "������� ���� � ������� ��/��/����: ";
    scanf("%d/%d/%d", &user_date.day, &user_date.month, &user_date.year);

    cout << "\n���� ����: "
        << user_date.day << "/"
        << user_date.month << "/"
        << user_date.year << endl;

    return 0;
}
