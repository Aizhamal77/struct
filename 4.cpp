#include <iostream>
using namespace std;

class Employee {
private:
    int empNumber;   
    float salary;   

public:
   
    Employee() : empNumber(0), salary(0.0f) {}

    void inputData() {
        cout << "Введите номер сотрудника: ";
        cin >> empNumber;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
    }

  
    void displayData() const {
        cout << "Номер сотрудника: " << empNumber << endl;
        cout << "Оклад сотрудника: " << salary << endl;
    }
};


void inputEmployees(Employee* emp, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Введите данные для сотрудника " << i + 1 << ":\n";
        emp[i].inputData();
    }
}


void displayEmployees(const Employee* emp, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nДанные сотрудника " << i + 1 << ":\n";
        emp[i].displayData();
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    const int employeeCount = 3; 
    Employee employees[employeeCount]; 

    inputEmployees(employees, employeeCount);

    displayEmployees(employees, employeeCount);

    return 0;
}
