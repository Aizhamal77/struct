#include <iostream>
using namespace std;


struct employee{
    int employee_id;  
    float allowance;  
};


int main(){
    setlocale(LC_ALL, "Rus");
    employee emp1, emp2, emp3;  

    cout << "Введите данные о сотрудниках:" << endl;

    cout << "Сотрудник 1 - введите номер и пособие: ";
    cin >> emp1.employee_id >> emp1.allowance;

 
    cout << "Сотрудник 2 - введите номер и пособие: ";
    cin >> emp2.employee_id >> emp2.allowance;

   
    cout << "Сотрудник 3 - введите номер и пособие: ";
    cin >> emp3.employee_id >> emp3.allowance;

   
    cout << "\nИнформация о сотрудниках:" << endl;

    cout << "Сотрудник 1: Номер - " << emp1.employee_id << ", Пособие - $" << emp1.allowance << endl;
    cout << "Сотрудник 2: Номер - " << emp2.employee_id << ", Пособие - $" << emp2.allowance << endl;
    cout << "Сотрудник 3: Номер - " << emp3.employee_id << ", Пособие - $" << emp3.allowance << endl;

    return 0;
}
