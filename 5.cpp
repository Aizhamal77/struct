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

    cout << "Введите дату в формате ДД/ММ/ГГГГ: ";
    scanf("%d/%d/%d", &user_date.day, &user_date.month, &user_date.year);

    cout << "\nВаша дата: "
        << user_date.day << "/"
        << user_date.month << "/"
        << user_date.year << endl;

    return 0;
}
