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
        cout << "Ââåäèòå äàòó ïðèåìà íà ðàáîòó (MM/DD/YY): ";
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
        cout << "Ââåäèòå íîìåð ñîòðóäíèêà: ";
        cin >> empNumber;
        cout << "Ââåäèòå îêëàä ñîòðóäíèêà: ";
        cin >> salary;

        hireDate.getDate(); 

        cout << "Âûáåðèòå òèï ñîòðóäíèêà (0 - Ëàáîðàíò, 1 - Ñåêðåòàðü, 2 - Ìåíåäæåð, 3 - Èíæåíåð, 4 - Êëåðê): ";
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
        cout << "Íîìåð ñîòðóäíèêà: " << empNumber << endl;
        cout << "Îêëàä ñîòðóäíèêà: " << salary << endl;

        cout << "Äàòà ïðèåìà íà ðàáîòó: ";
        hireDate.showDate(); 

        cout << "\nÒèï ñîòðóäíèêà: ";
        switch (type) {
        case LABORANT: cout << "Ëàáîðàíò"; break;
        case SECRETARY: cout << "Ñåêðåòàðü"; break;
        case MANAGER: cout << "Ìåíåäæåð"; break;
        case ENGINEER: cout << "Èíæåíåð"; break;
        case CLERK: cout << "Êëåðê"; break;
        }
        cout << endl;
    }
};

void inputEmployees(Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nÂâåäèòå äàííûå äëÿ ñîòðóäíèêà " << i + 1 << ":\n";
        employees[i].getEmploy();
    }
}

void displayEmployees(const Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nÄàííûå ñîòðóäíèêà " << i + 1 << ":\n";
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
