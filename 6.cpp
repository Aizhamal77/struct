#include <iostream>
#include <string>
using namespace std;


enum Etype { LABORANT, SECRETARY, MANAGER, ENGINEER, CLERK };


class Date {
private:
    int month, day, year;  

public:
    void getDate() {
        char slash;
        cout << "Введите дату приема на работу (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {
        cout << month << "/" << day << "/" << year;
    }
};

class Employee {
private:
    int empNumber;   
    float salary;  
    Date hireDate;   
    Etype type;    

public:
    Employee() : empNumber(0), salary(0.0f), type(LABORANT) {}

    void getEmploy() {
        int typeChoice;
        cout << "Введите номер сотрудника: ";
        cin >> empNumber;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;

        hireDate.getDate(); 

        cout << "Выберите тип сотрудника (0 - Лаборант, 1 - Секретарь, 2 - Менеджер, 3 - Инженер, 4 - Клерк): ";
        cin >> typeChoice;

        switch (typeChoice) {
        case 0: type = LABORANT; break;
        case 1: type = SECRETARY; break;
        case 2: type = MANAGER; break;
        case 3: type = ENGINEER; break;
        case 4: type = CLERK; break;
        default: type = LABORANT; break;
        }
    }

    void putEmploy() const {
        cout << "Номер сотрудника: " << empNumber << endl;
        cout << "Оклад сотрудника: " << salary << endl;

        cout << "Дата приема на работу: ";
        hireDate.showDate(); 

        cout << "\nТип сотрудника: ";
        switch (type) {
        case LABORANT: cout << "Лаборант"; break;
        case SECRETARY: cout << "Секретарь"; break;
        case MANAGER: cout << "Менеджер"; break;
        case ENGINEER: cout << "Инженер"; break;
        case CLERK: cout << "Клерк"; break;
        }
        cout << endl;
    }
};

void inputEmployees(Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nВведите данные для сотрудника " << i + 1 << ":\n";
        employees[i].getEmploy();
    }
}

void displayEmployees(const Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nДанные сотрудника " << i + 1 << ":\n";
        employees[i].putEmploy();
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
