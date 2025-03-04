#include <iostream>
using namespace std;


struct sterling {
    int pounds; 
    int shillings; 
    int pence;     
};

int main() {
    setlocale(LC_ALL, "Rus");
    double decimalPounds;

    cout << "Введите сумму в фунтах (десятичная система): ";
    cin >> decimalPounds;


    sterling money;
    money.pounds = int(decimalPounds); 
    money.shillings = int((decimalPounds - money.pounds) * 20); 
    money.pence = int(((decimalPounds - money.pounds) * 20 - money.shillings) * 12); 

   
    cout << "Сумма в старой системе: "
        << money.pounds << " фунтов, "
        << money.shillings << " шиллингов, "
        << money.pence << " пенсов." << endl;

    return 0;
}
