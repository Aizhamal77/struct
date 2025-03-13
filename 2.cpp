#include <iostream> 
#include <string> 
using namespace std;

class employee{
private:
    string name;
    long number;
public:
    void getdata() {
        cout << "\nВведите имя:"; cin >> name;
        cout << "Введите номер:"; cin >> number;
    }
    void putdata(){
        cout << "\n Имя:" << name;
        cout << "\n Номер:" << number;
    }
};

int main(){
    setlocale(LC_ALL, "Rus");

    employee emparr[100]; 
    int n = 0;              
    char ch;               
    do {                   
        cout << "\nВведите данные о работнике с номером " << n + 1;
        emparr[n++].getdata();
        cout << "Продолжить (y/n)?"; cin >> ch;
    } while (ch != 'n');
    for (int j = 0; j < n; j++){
        cout << "\nНомер работника " << j + 1;
        emparr[j].putdata();
    }
    cout << endl;
    return 0;
}